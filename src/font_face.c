#include <stdio.h>
#include <stdlib.h>

#include <pango/pango.h>
#include <cairo.h>
#include "common/common.h"
#include "common/table.h"

#include "font_face.h"

const CommonEnum CairoFontType[] = {
    { "Toy", CAIRO_FONT_TYPE_TOY },
    { "Ft", CAIRO_FONT_TYPE_FT },
    { "Win32", CAIRO_FONT_TYPE_WIN32 },
    { "Quartz", CAIRO_FONT_TYPE_QUARTZ },
    { "User", CAIRO_FONT_TYPE_USER },
    { NULL, -1 }
};

/*cairo_font_face_t * 	cairo_font_face_reference ()*/
/*void 	cairo_font_face_destroy ()*/
static int _cairo_font_face_destroy(lua_State *L) {
    cairo_font_face_t* face = commonGetAs(L, 1, FontFaceName, cairo_font_face_t *);
    cairo_font_face_destroy(face);

    return 0;
}
/*cairo_status_t 	cairo_font_face_status ()*/
/*cairo_font_type_t 	cairo_font_face_get_type ()*/
/*unsigned int 	cairo_font_face_get_reference_count ()*/
/*cairo_status_t 	cairo_font_face_set_user_data ()*/
/*void * 	cairo_font_face_get_user_data ()*/


const luaL_Reg FontFaceFunctions[] = {
    /*{ "glyphStringNew", _pango_glyph_string_new },*/
    { NULL, NULL }
};

static const luaL_Reg methods[] = {
    /*{ "copy", _pango_glyph_string_copy },*/
    { NULL, NULL }
};

static const luaL_Reg metamethods[] = {
    { "__gc", _cairo_font_face_destroy },
    { NULL, NULL }
};

const CommonObject FontFace = {
    "Cairo.FontFace",
    methods,
    metamethods
};
