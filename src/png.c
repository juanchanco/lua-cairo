#include <cairo.h>
#ifdef CAIRO_HAS_PNG_FUNCTIONS
#include "image_surface.h"
#include "png.h"

/*#define 	CAIRO_HAS_PNG_FUNCTIONS*/
/*cairo_surface_t * 	cairo_image_surface_create_from_png ()*/
/*cairo_status_t 	(*cairo_read_func_t) ()*/
/*cairo_surface_t * 	cairo_image_surface_create_from_png_stream ()*/
int _cairo_surface_write_to_png (lua_State* L) {
    cairo_surface_t *surf = commonGetAs(L, 1, ImageSurfaceName, cairo_surface_t *);
    const char* fname = luaL_checkstring (L, 2);
    cairo_status_t status = cairo_surface_write_to_png(surf, fname);
    if (status != CAIRO_STATUS_SUCCESS) {
        return commonPushCairoError(L, status);
    }
    return commonPush(L, "b", 1);
}
/*cairo_status_t 	(*cairo_write_func_t) ()*/
/*cairo_status_t 	cairo_surface_write_to_png_stream ()*/

#endif /* CAIRO_HAS_PNG_FUNCTIONS */
