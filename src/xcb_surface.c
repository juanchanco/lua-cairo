#include <cairo.h>
#ifdef CAIRO_HAS_XCB_SURFACE
#include <cairo-xcb.h>
#include <xcb/xcb.h>
#include "common/table.h"
#include "context.h"
/*TODO: figure out a better way to ingrate these libraries*/
#include "../lua-xcb/src/lua_xcb.h"
#include "xcb_surface.h"

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

/*cairo_surface_t * 	cairo_xcb_surface_create ()*/
static int _cairo_xcb_surface_create(lua_State* L) {
    xcb_connection_t *conn = commonGetAs(L, 1, ConnectionName, xcb_connection_t *);
    int window = luaL_checkinteger(L, 2);
    int root_visual = tableGetInt(L, 3, "root_visual");
    xcb_visualtype_t* visual = find_visual(conn, root_visual);
    if (!visual) {
        return commonPushError(L, "find_visual failed");
    }
    int width = luaL_checkinteger(L, 4);
    int height = luaL_checkinteger(L, 5);
    cairo_surface_t* result =
        cairo_xcb_surface_create(conn, window, visual, width, height);
    cairo_status_t status = cairo_surface_status(result);
    if (status != CAIRO_STATUS_SUCCESS) {
        return commonPushCairoError(L, status);
    }
    return commonPush(L, "p", XcbSurfaceName, result);
}

/*cairo_surface_t * 	cairo_xcb_surface_create_for_bitmap ()*/
/*cairo_surface_t * 	cairo_xcb_surface_create_with_xrender_format ()*/
/*void 	cairo_xcb_surface_set_size ()*/
/*void 	cairo_xcb_surface_set_drawable ()*/
/*xcb_connection_t * 	cairo_xcb_device_get_connection ()*/
/*void 	cairo_xcb_device_debug_cap_xrender_version ()*/
/*void 	cairo_xcb_device_debug_cap_xshm_version ()*/
/*int 	cairo_xcb_device_debug_get_precision ()*/
/*void 	cairo_xcb_device_debug_set_precision ()*/
const luaL_Reg XcbSurfaceFunctions[] = {
    { "xcbSurfaceCreate", _cairo_xcb_surface_create },
    { NULL, NULL }
};

/*TODO: need to release any xcb resources?*/
static const luaL_Reg methods[] = {
    { NULL, NULL }
};


static const luaL_Reg metamethods[] = {
    { NULL, NULL }
};


const CommonObject XcbSurface = {
    "Cairo.Surface.Xcb",
    methods,
    metamethods
};
#endif /* CAIRO_HAS_XCB_SURFACE */
