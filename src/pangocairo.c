#include "pangocairo.h"

/*PangoFontMap * 	pango_cairo_font_map_get_default ()*/
/*void 	pango_cairo_font_map_set_default ()*/
/*PangoFontMap * 	pango_cairo_font_map_new ()*/
/*PangoFontMap * 	pango_cairo_font_map_new_for_font_type ()*/
/*cairo_font_type_t 	pango_cairo_font_map_get_font_type ()*/
/*void 	pango_cairo_font_map_set_resolution ()*/
/*double 	pango_cairo_font_map_get_resolution ()*/
/*PangoContext * 	pango_cairo_font_map_create_context ()*/
/*cairo_scaled_font_t * 	pango_cairo_font_get_scaled_font ()*/
/*void 	pango_cairo_context_set_resolution ()*/
/*double 	pango_cairo_context_get_resolution ()*/
/*void 	pango_cairo_context_set_font_options ()*/
/*const cairo_font_options_t * 	pango_cairo_context_get_font_options ()*/
/*void 	(*PangoCairoShapeRendererFunc) ()*/
/*void 	pango_cairo_context_set_shape_renderer ()*/
/*PangoCairoShapeRendererFunc 	pango_cairo_context_get_shape_renderer ()*/
/*PangoContext * 	pango_cairo_create_context ()*/
/*void 	pango_cairo_update_context ()*/
int _pango_cairo_create_layout (lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, "Context", cairo_t *);
    PangoLayout* result = pango_cairo_create_layout(cr);
    return commonPush(L, "p", "Layout", result);
}

int _pango_cairo_update_layout (lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, "Context", cairo_t *);
    PangoLayout *layout = commonGetAs(L, 2, "Layout", PangoLayout *);
    pango_cairo_update_layout(cr, layout);
    return commonPush(L, "b", 1);
}
/*void 	pango_cairo_show_glyph_string ()*/
/*void 	pango_cairo_show_glyph_item ()*/
/*void 	pango_cairo_show_layout_line ()*/
int _pango_cairo_show_layout (lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, "Context", cairo_t *);
    PangoLayout *layout = commonGetAs(L, 2, "Layout", PangoLayout *);
    pango_cairo_show_layout(cr, layout);
    return commonPush(L, "b", 1);
}
/*void 	pango_cairo_show_error_underline ()*/
/*void 	pango_cairo_glyph_string_path ()*/
/*void 	pango_cairo_layout_line_path ()*/
/*void 	pango_cairo_layout_path ()*/
/*void 	pango_cairo_error_underline_path ()*/

