#include <stdlib.h>
#include <cairo-xcb.h>
#include <xcb/xcb.h>
#include "common/table.h"
#include "context.h"
#include "xcb_connection.h"

const CommonEnum XcbConnectionError[] = {
    { "Error", XCB_CONN_ERROR },
    { "ClosedExtNotsupported", XCB_CONN_CLOSED_EXT_NOTSUPPORTED },
    { "ClosedMemInsufficient", XCB_CONN_CLOSED_MEM_INSUFFICIENT },
    { "ClosedReqLenExceed", XCB_CONN_CLOSED_REQ_LEN_EXCEED },
    { "ClosedParseErr", XCB_CONN_CLOSED_PARSE_ERR },
    { "ClosedInvalidScreen", XCB_CONN_CLOSED_INVALID_SCREEN },
    { "ClosedFdpassingFailed", XCB_CONN_CLOSED_FDPASSING_FAILED }, 
    { NULL, -1 }
};
const CommonEnum XcbWindowClass[] = {
    { "CopyFromParent", XCB_WINDOW_CLASS_COPY_FROM_PARENT },
    { "InputOutput", XCB_WINDOW_CLASS_INPUT_OUTPUT },
    { "InputOnly", XCB_WINDOW_CLASS_INPUT_ONLY },
    { NULL, -1 }
};
const CommonEnum XcbCW[] = {
    { "BackPixmap", XCB_CW_BACK_PIXMAP },
    { "BackPixel", XCB_CW_BACK_PIXEL },
    { "BorderPixmap", XCB_CW_BORDER_PIXMAP },
    { "BorderPixel", XCB_CW_BORDER_PIXEL },
    { "BitGravity", XCB_CW_BIT_GRAVITY },
    { "WinGravity", XCB_CW_WIN_GRAVITY },
    { "BackingStore", XCB_CW_BACKING_STORE },
    { "BackingPlanes", XCB_CW_BACKING_PLANES },
    { "BackingPixel", XCB_CW_BACKING_PIXEL },
    { "OverrideRedirect", XCB_CW_OVERRIDE_REDIRECT },
    { "SaveUnder", XCB_CW_SAVE_UNDER },
    { "EventMask", XCB_CW_EVENT_MASK },
    { "DontPropagate", XCB_CW_DONT_PROPAGATE },
    { "Colormap", XCB_CW_COLORMAP },
    { "Cursor", XCB_CW_CURSOR },
    { NULL, -1 }
};

const CommonEnum XcbDefines[] = {
    { "None", XCB_NONE },
    { "CopyFromParent", XCB_COPY_FROM_PARENT },
    { "CurrentTime", XCB_CURRENT_TIME },
    { "NoSymbol", XCB_NO_SYMBOL },
    { "Expose", XCB_EXPOSE },
    { "KeyPress", XCB_KEY_PRESS },
    { NULL, -1 }
};
static xcb_visualtype_t *find_visual(xcb_connection_t *c, xcb_visualid_t visual) {
    xcb_screen_iterator_t screen_iter = xcb_setup_roots_iterator(xcb_get_setup(c));

    for (; screen_iter.rem; xcb_screen_next(&screen_iter)) {
        xcb_depth_iterator_t depth_iter = xcb_screen_allowed_depths_iterator(screen_iter.data);
        for (; depth_iter.rem; xcb_depth_next(&depth_iter)) {
            xcb_visualtype_iterator_t visual_iter = xcb_depth_visuals_iterator(depth_iter.data);
            for (; visual_iter.rem; xcb_visualtype_next(&visual_iter))
                if (visual == visual_iter.data->visual_id)
                    return visual_iter.data;
        }
    }

    return NULL;
}

static int _find_visual(lua_State* L) {
    xcb_connection_t *conn = commonGetAs(L, 1, XcbConnectionName, xcb_connection_t *);
    uint32_t visual = (uint32_t) luaL_checkinteger(L, 2);
    xcb_visualtype_t* result = find_visual(conn, visual);
    if (!result) {
        return commonPushError(L, "find_visual failed");
    }
    return commonPush(L, "p", XcbVisualName, result);
};

static int _xcb_connect(lua_State* L) {
    /*TODO: make this optional*/
	luaL_checktype(L, 1, LUA_TTABLE);
    const char* displayname = tableGetString(L, 1, "displayname");
    int screenp = (uint32_t) tableGetInt(L, 1, "screenp");
    xcb_connection_t* result = xcb_connect(displayname, &screenp);

    if (xcb_connection_has_error(result)) {
        return commonPushError(L, "Some XCB error");
    }
    return commonPush(L, "p", XcbConnectionName, result);
}

/*typedef struct xcb_screen_t {
    xcb_window_t   root; [>*<  <]
    xcb_colormap_t default_colormap; [>*<  <]
    uint32_t       white_pixel; [>*<  <]
    uint32_t       black_pixel; [>*<  <]
    uint32_t       current_input_masks; [>*<  <]
    uint16_t       width_in_pixels; [>*<  <]
    uint16_t       height_in_pixels; [>*<  <]
    uint16_t       width_in_millimeters; [>*<  <]
    uint16_t       height_in_millimeters; [>*<  <]
    uint16_t       min_installed_maps; [>*<  <]
    uint16_t       max_installed_maps; [>*<  <]
    xcb_visualid_t root_visual; [>*<  <]
    uint8_t        backing_stores; [>*<  <]
    uint8_t        save_unders; [>*<  <]
    uint8_t        root_depth; [>*<  <]
    uint8_t        allowed_depths_len; [>*<  <]
} xcb_screen_t;*/

static int _xcb_create_screen(lua_State* L) {
    xcb_connection_t *conn = commonGetAs(L, 1, XcbConnectionName, xcb_connection_t *);
    xcb_screen_t *screen = xcb_setup_roots_iterator(xcb_get_setup(conn)).data;
    lua_newtable(L);
    tableSetInt(L, -1, "root", screen->root);
    tableSetInt(L, -1, "defaultColormap", screen->default_colormap);
    tableSetInt(L, -1, "whitePixel", screen->white_pixel);
    tableSetInt(L, -1, "blackPixel", screen->black_pixel);
    tableSetInt(L, -1, "currentInputMasks", screen->current_input_masks);
    tableSetInt(L, -1, "widthInPixels", screen->width_in_pixels);
    tableSetInt(L, -1, "heightInPixels", screen->height_in_pixels);
    tableSetInt(L, -1, "widthInMillimeters", screen->width_in_millimeters);
    tableSetInt(L, -1, "heightInMillimeters", screen->height_in_millimeters);
    tableSetInt(L, -1, "minInstalledMaps", screen->min_installed_maps);
    tableSetInt(L, -1, "maxInstalledMaps", screen->max_installed_maps);
    tableSetInt(L, -1, "rootVisual", screen->root_visual);
    tableSetInt(L, -1, "backingStores", screen->backing_stores);
    tableSetInt(L, -1, "saveUnders", screen->save_unders);
    tableSetInt(L, -1, "rootDepth", screen->root_depth);
    tableSetInt(L, -1, "allowedDepthsLen", screen->allowed_depths_len);
    /*TODO: need to free screen?*/
    return 1;
}
static int _xcb_generate_id(lua_State* L) {
    xcb_connection_t *conn = commonGetAs(L, 1, XcbConnectionName, xcb_connection_t *);
    xcb_window_t wid = xcb_generate_id(conn);
    return commonPush(L, "i", wid);
}

static int _xcb_create_window(lua_State* L) {
    xcb_connection_t *conn = commonGetAs(L, 1, XcbConnectionName, xcb_connection_t *);
	luaL_checktype(L, 2, LUA_TTABLE);
    /*TODO: luasdl2 has a tableGetType wrapping the optional ones*/
    /*NOTE: if missing will be 0 with is CopyFromParent */
    uint8_t depth = (uint8_t) tableGetInt(L, 2, "depth");
    /*TODO: check for zero*/
    uint32_t wid = (uint32_t) tableGetInt(L, 2, "window");
    uint32_t parent = (uint32_t) tableGetInt(L, 2, "parent");
    int16_t x = (int16_t) tableGetInt(L, 2, "x");
    int16_t y = (int16_t) tableGetInt(L, 2, "y");
    /*TODO: check for zero?*/
    uint16_t width = (uint16_t) tableGetInt(L, 2, "width");
    uint16_t height = (uint16_t) tableGetInt(L, 2, "height");
    /*NOTE: border must be 0 if class is InputOnly*/
    uint16_t border = (uint16_t) tableGetInt(L, 2, "border");
    /*TODO: check for zero*/
    uint16_t class = (uint16_t) tableGetInt(L, 2, "class");
    /*TODO: check for zero*/
    uint32_t visual = (uint32_t) tableGetInt(L, 2, "visual");
    uint32_t value_mask = (uint32_t) tableGetEnum(L, 2, "value_mask");
    /*TODO: figure this out. its const uint32_t* (list) */
    /*uint32_t mask = (uint32_t) tableGetInt(L, 2, "mask");*/
    uint32_t mask[2];
    mask[0] = 1;
    mask[1] = XCB_EVENT_MASK_EXPOSURE;
    /*TODO: what to do with void cookie */
    xcb_create_window(conn, depth, wid, parent,
            x, y, width, height, border,
            class, visual, value_mask, mask);
    return 0;
};

static int _xcb_map_window(lua_State* L) {
    xcb_connection_t *conn = commonGetAs(L, 1, XcbConnectionName, xcb_connection_t *);
    uint32_t wid = (uint32_t) luaL_checkinteger(L, 2);
    xcb_map_window(conn, wid);
    return 0;
};

static int _xcb_flush(lua_State* L) {
    xcb_connection_t *conn = commonGetAs(L, 1, XcbConnectionName, xcb_connection_t *);
    xcb_flush(conn);
    return 0;
};

/*NOTE: this is blocking*/
static int _xcb_wait_for_event(lua_State* L) {
    xcb_connection_t *conn = commonGetAs(L, 1, XcbConnectionName, xcb_connection_t *);
    xcb_generic_event_t* evt = xcb_wait_for_event(conn);
    return commonPush(L, "p", XcbEventName, evt);
}

static int _xcb_disconnect(lua_State* L) {
    printf("GC: xcb_disconnect\n");
    CommonUserdata *conn = commonGetUserdata(L, 1, XcbConnectionName);
    /*if (path->mustdelete) {*/
    xcb_disconnect(conn->data);
    /*}*/

    return 0;
};

const luaL_Reg XcbConnectionFunctions[] = {
    { "xcbConnect", _xcb_connect },
    { NULL, NULL }
};


static const luaL_Reg methods[] = {
    { "generateId", _xcb_generate_id },
    { "createWindow", _xcb_create_window },
    { "mapWindow", _xcb_map_window },
    { "flush", _xcb_flush },
    { "waitForEvent", _xcb_wait_for_event },
    { "createScreen", _xcb_create_screen },
    { "findVisual", _find_visual },
    { NULL, NULL }
};


static const luaL_Reg metamethods[] = {
    { "__gc", _xcb_disconnect },
    { NULL, NULL }
};


const CommonObject XcbConnection = {
    "XcbConnection",
    methods,
    metamethods
};
static int evt_response_type(lua_State* L) {
    xcb_generic_event_t *evt = commonGetAs(L, 1, XcbEventName, xcb_generic_event_t *);
    return commonPush(L, "i", evt->response_type & ~0x80);
};
static int evt_count(lua_State* L) {
    xcb_generic_event_t *evt = commonGetAs(L, 1, XcbEventName, xcb_generic_event_t *);
    /*TODO: flesh out event object*/
    return commonPush(L, "i", ((xcb_expose_event_t *) evt)->count);
};
static int _free_event(lua_State* L) {
    xcb_generic_event_t *evt = commonGetAs(L, 1, XcbEventName, xcb_generic_event_t *);
    free(evt);

    return 0;
};

static const luaL_Reg evt_metamethods[] = {
    { "__gc", _free_event },
    { NULL, NULL }
};

static const luaL_Reg evt_methods[] = {
    { "getResonseType", evt_response_type },
    { "getCount", evt_count },
    { NULL, NULL }
};

const CommonObject XcbEvent = {
    "XcbEvent",
    evt_methods,
    evt_metamethods
};

const CommonObject XcbVisual = {
    "XcbVisual",
    NULL,
    NULL
};


/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
#include <xcb/xcb.h>
 
int main ()
{
  xcb_connection_t    *c;
  xcb_screen_t        *screen;
  xcb_drawable_t       win;
  xcb_gcontext_t       foreground;
  xcb_gcontext_t       background;
  xcb_generic_event_t *e;
  uint32_t             mask = 0;
  uint32_t             values[2];
 
  char string[] = "Hello, XCB!";
  uint8_t string_len = strlen(string);
 
  xcb_rectangle_t rectangles[] = {
    {40, 40, 20, 20},
  };
 
  c = xcb_connect (NULL, NULL);
 
  [> get the first screen <]
  screen = xcb_setup_roots_iterator (xcb_get_setup (c)).data;
 
  [> root window <]
  win = screen->root;
 
  [> create black (foreground) graphic context <]
  foreground = xcb_generate_id (c);
  mask = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
  values[0] = screen->black_pixel;
  values[1] = 0;
  xcb_create_gc (c, foreground, win, mask, values);
 
  [> create white (background) graphic context <]
  background = xcb_generate_id (c);
  mask = XCB_GC_BACKGROUND | XCB_GC_GRAPHICS_EXPOSURES;
  values[0] = screen->white_pixel;
  values[1] = 0;
  xcb_create_gc (c, background, win, mask, values);
 
  [> create the window <]
  win = xcb_generate_id(c);
  mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
  values[0] = screen->white_pixel;
  values[1] = XCB_EVENT_MASK_EXPOSURE | XCB_EVENT_MASK_KEY_PRESS;
  xcb_create_window (c,                             [> connection    <]
                     XCB_COPY_FROM_PARENT,          [> depth         <]
                     win,                           [> window Id     <]
                     screen->root,                  [> parent window <]
                     0, 0,                          [> x, y          <]
                     150, 150,                      [> width, height <]
                     10,                            [> border_width  <]
                     XCB_WINDOW_CLASS_INPUT_OUTPUT, [> class         <]
                     screen->root_visual,           [> visual        <]
                     mask, values);                 [> masks         <]
 
  [> map the window on the screen <]
  xcb_map_window (c, win);
 
  xcb_flush (c);
 
  while ((e = xcb_wait_for_event (c))) {
    switch (e->response_type & ~0x80) {
    case XCB_EXPOSE:
      xcb_poly_rectangle (c, win, foreground, 1, rectangles);
      xcb_image_text_8 (c, string_len, win, background, 20, 20, string);
      xcb_flush (c);
      break;
    case XCB_KEY_PRESS:
      goto endloop;
    }
    free (e);
  }
  endloop:
 
  return 0;
}*/
