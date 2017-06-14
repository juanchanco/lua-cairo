#include <stdio.h>
#include <stdlib.h>

#include <pango/pango.h>
#include <cairo.h>
#include "common/common.h"
#include "common/table.h"

#include "scaled_font.h"

/*cairo_scaled_font_t * 	cairo_scaled_font_create ()*/
/*cairo_scaled_font_t * 	cairo_scaled_font_reference ()*/
static int _cairo_scaled_font_destroy(lua_State *L) {
    cairo_scaled_font_t* font = commonGetAs(L, 1, ScaledFontName, cairo_scaled_font_t *);
    cairo_scaled_font_destroy(font);

    return 0;
}
/*cairo_status_t 	cairo_scaled_font_status ()*/
/*void 	cairo_scaled_font_extents ()*/
/*void 	cairo_scaled_font_text_extents ()*/
/*void 	cairo_scaled_font_glyph_extents ()*/
/*cairo_status_t 	cairo_scaled_font_text_to_glyphs ()*/
/*cairo_font_face_t * 	cairo_scaled_font_get_font_face ()*/
/*void 	cairo_scaled_font_get_font_options ()*/
/*void 	cairo_scaled_font_get_font_matrix ()*/
/*void 	cairo_scaled_font_get_ctm ()*/
/*void 	cairo_scaled_font_get_scale_matrix ()*/
/*cairo_font_type_t 	cairo_scaled_font_get_type ()*/
/*unsigned int 	cairo_scaled_font_get_reference_count ()*/
/*cairo_status_t 	cairo_scaled_font_set_user_data ()*/
/*void * 	cairo_scaled_font_get_user_data ()*/

const luaL_Reg ScaledFontFunctions[] = {
    /*{ "glyphStringNew", _pango_glyph_string_new },*/
    { NULL, NULL }
};

static const luaL_Reg methods[] = {
    /*{ "copy", _pango_glyph_string_copy },*/
    { NULL, NULL }
};

static const luaL_Reg metamethods[] = {
    { "__gc", _cairo_scaled_font_destroy },
    { NULL, NULL }
};

const CommonObject ScaledFont = {
    "Pango.ScaledFont",
    methods,
    metamethods
};
