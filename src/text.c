#include "text.h"
#include "context.h"
const CommonEnum CairoFontSlant[] = {
    { "Normal", CAIRO_FONT_SLANT_NORMAL },
    { "Italic", CAIRO_FONT_SLANT_ITALIC },
    { "Oblique", CAIRO_FONT_SLANT_OBLIQUE },
    { NULL, -1 }
};
const CommonEnum CairoFontWeight[] = {
    { "Normal", CAIRO_FONT_WEIGHT_NORMAL },
    { "Bold", CAIRO_FONT_WEIGHT_BOLD },
    { NULL, -1 }
};

int _cairo_select_font_face (lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    const char* str = luaL_checkstring (L, 2);
    int slant = commonGetEnum(L, 3);
    int weight = commonGetEnum(L, 4);
    cairo_select_font_face(cr, str, slant, weight);
    return commonPush(L, "b", 1);
}
int _cairo_set_font_size (lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    double size = (double) luaL_checknumber(L, 2);
    cairo_set_font_size(cr, size);
    return commonPush(L, "b", 1);
}
/*void 	cairo_set_font_matrix ()*/
/*void 	cairo_get_font_matrix ()*/
/*void 	cairo_set_font_options ()*/
/*void 	cairo_get_font_options ()*/
/*void 	cairo_set_font_face ()*/
/*cairo_font_face_t * 	cairo_get_font_face ()*/
/*void 	cairo_set_scaled_font ()*/
/*cairo_scaled_font_t * 	cairo_get_scaled_font ()*/
int _cairo_show_text (lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    const char* text = luaL_checkstring (L, 2);
    cairo_show_text(cr, text);
    return commonPush(L, "b", 1);
}
/*void 	cairo_show_glyphs ()*/
/*void 	cairo_show_text_glyphs ()*/
/*void 	cairo_font_extents ()*/
/*typedef struct {
    double x_bearing;
    double y_bearing;
    double width;
    double height;
    double x_advance;
    double y_advance;
} cairo_text_extents_t;*/
int _cairo_text_extents (lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, ContextName, cairo_t *);
    const char* text = luaL_checkstring (L, 2);
    cairo_text_extents_t te;
    cairo_text_extents(cr, text, &te);
    /*TODO: create a map/object to return*/
    return commonPush(L, "b", 1);
}
/*void 	cairo_glyph_extents ()*/
/*cairo_font_face_t * 	cairo_toy_font_face_create ()*/
/*const char * 	cairo_toy_font_face_get_family ()*/
/*cairo_font_slant_t 	cairo_toy_font_face_get_slant ()*/
/*cairo_font_weight_t 	cairo_toy_font_face_get_weight ()*/
/*cairo_glyph_t * 	cairo_glyph_allocate ()*/
/*void 	cairo_glyph_free ()*/
/*cairo_text_cluster_t * 	cairo_text_cluster_allocate ()*/
/*void 	cairo_text_cluster_free ()*/

