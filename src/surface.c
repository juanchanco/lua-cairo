#include <cairo.h>
#include "context.h"
#include "surface.h"
#ifdef CAIRO_HAS_PNG_FUNCTIONS
#include "png.h"
#endif /* CAIRO_HAS_PNG_FUNCTIONS */

const CommonEnum CairoContent[] = {
/*CAIRO_CONTENT_COLOR*/
/*CAIRO_CONTENT_ALPHA*/
/*CAIRO_CONTENT_COLOR_ALPHA*/
    { NULL, -1 }
};
const CommonEnum CairoSurfaceType[] = {
/*CAIRO_SURFACE_TYPE_IMAGE*/
/*CAIRO_SURFACE_TYPE_PDF*/
/*CAIRO_SURFACE_TYPE_PS*/
/*CAIRO_SURFACE_TYPE_XLIB*/
/*CAIRO_SURFACE_TYPE_XCB*/
/*CAIRO_SURFACE_TYPE_GLITZ*/
/*CAIRO_SURFACE_TYPE_QUARTZ*/
/*CAIRO_SURFACE_TYPE_WIN32*/
/*CAIRO_SURFACE_TYPE_BEOS*/
/*CAIRO_SURFACE_TYPE_DIRECTFB*/
/*CAIRO_SURFACE_TYPE_SVG*/
/*CAIRO_SURFACE_TYPE_OS2*/
/*CAIRO_SURFACE_TYPE_WIN32_PRINTING*/
/*CAIRO_SURFACE_TYPE_QUARTZ_IMAGE*/
/*CAIRO_SURFACE_TYPE_SCRIPT*/
/*CAIRO_SURFACE_TYPE_QT*/
/*CAIRO_SURFACE_TYPE_RECORDING*/
/*CAIRO_SURFACE_TYPE_VG*/
/*CAIRO_SURFACE_TYPE_GL*/
/*CAIRO_SURFACE_TYPE_DRM*/
/*CAIRO_SURFACE_TYPE_TEE*/
/*CAIRO_SURFACE_TYPE_XML*/
/*CAIRO_SURFACE_TYPE_SKIA*/
/*CAIRO_SURFACE_TYPE_SUBSURFACE*/
/*CAIRO_SURFACE_TYPE_COGL*/
    { NULL, -1 }
};
 
static int _cairo_create(lua_State* L) {
    CommonUserdata* surface = commonGetUserdataBase(L, 1, SurfaceName);
    cairo_t* result = cairo_create(surface->data);
    cairo_status_t status = cairo_status(result);
    if (status != CAIRO_STATUS_SUCCESS) {
        return commonPushCairoError(L, status);
    }
    return commonPush(L, "p", ContextName, result);
}
/*cairo_surface_t * 	cairo_surface_create_similar ()*/
/*cairo_surface_t * 	cairo_surface_create_similar_image ()*/
/*cairo_surface_t * 	cairo_surface_create_for_rectangle ()*/
/*cairo_surface_t * 	cairo_surface_reference ()*/
/*void 	cairo_surface_destroy ()*/
/*cairo_status_t 	cairo_surface_status ()*/
/*void 	cairo_surface_finish ()*/
static int _cairo_surface_flush(lua_State* L) {
    CommonUserdata* surface = commonGetUserdataBase(L, 1, SurfaceName);
    cairo_surface_flush(surface->data);
    return 0;
}
/*cairo_device_t * 	cairo_surface_get_device ()*/
/*void 	cairo_surface_get_font_options ()*/
/*cairo_content_t 	cairo_surface_get_content ()*/
/*void 	cairo_surface_mark_dirty ()*/
/*void 	cairo_surface_mark_dirty_rectangle ()*/
/*void 	cairo_surface_set_device_offset ()*/
/*void 	cairo_surface_get_device_offset ()*/
/*void 	cairo_surface_get_device_scale ()*/
/*void 	cairo_surface_set_device_scale ()*/
/*void 	cairo_surface_set_fallback_resolution ()*/
/*void 	cairo_surface_get_fallback_resolution ()*/
/*cairo_surface_type_t 	cairo_surface_get_type ()*/
/*unsigned int 	cairo_surface_get_reference_count ()*/
/*cairo_status_t 	cairo_surface_set_user_data ()*/
/*void * 	cairo_surface_get_user_data ()*/
/*void 	cairo_surface_copy_page ()*/
/*void 	cairo_surface_show_page ()*/
/*cairo_bool_t 	cairo_surface_has_show_text_glyphs ()*/
/*cairo_status_t 	cairo_surface_set_mime_data ()*/
/*void 	cairo_surface_get_mime_data ()*/
/*cairo_bool_t 	cairo_surface_supports_mime_type ()*/
/*cairo_surface_t * 	cairo_surface_map_to_image ()*/
/*void 	cairo_surface_unmap_image ()*/

/*TODO: inheritence*/
#ifdef CAIRO_HAS_PNG_FUNCTIONS
int _cairo_surface_write_to_png (lua_State* L) {
    CommonUserdata *surface = commonGetUserdataBase(L, 1, SurfaceName);
    cairo_surface_t *surf = (cairo_surface_t*) surface->data;
    const char* fname = luaL_checkstring (L, 2);
    cairo_status_t status = cairo_surface_write_to_png(surf, fname);
    if (status != CAIRO_STATUS_SUCCESS) {
        return commonPushCairoError(L, status);
    }
    return commonPush(L, "b", 1);
}
#endif /* CAIRO_HAS_PNG_FUNCTIONS */

static int _cairo_surface_destroy(lua_State* L) {
    CommonUserdata *surface = commonGetUserdataBase(L, 1, SurfaceName);
    /*TODO: check for null*/
    /*printf("GC: cairo_surface_destroy (Surface)\n");*/
    /*if (surface->mustdelete) {*/
    cairo_surface_finish(surface->data);
    cairo_surface_destroy(surface->data);
    /*}*/

    return 0;
}

const luaL_Reg SurfaceFunctions[] = {
    { NULL, NULL }
};


static const luaL_Reg methods[] = {
    { "createContext", _cairo_create },
    { "flush", _cairo_surface_flush },
    /* TODO: have a "not available" method when is it not */
#ifdef CAIRO_HAS_PNG_FUNCTIONS
    { "writeToPng", _cairo_surface_write_to_png },
#endif /* CAIRO_HAS_PNG_FUNCTIONS */
    { NULL, NULL }
};


static const luaL_Reg metamethods[] = {
    { "__gc", _cairo_surface_destroy },
    { NULL, NULL }
};


const CommonObject Surface = {
    "Surface",
    methods,
    metamethods
};
