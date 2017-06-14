#include "context.h"
#include "pangocairo.h"
#include "../lua-pango/src/lua_pango.h"

static int _pango_cairo_font_map_get_default (lua_State* L) {
    PangoFontMap* result = pango_cairo_font_map_get_default();
    return commonPush(L, "p", PangoFontMapName, result);
}
//https://developer.gnome.org/pango/stable/pango-Cairo-Rendering.html
/*void 	pango_cairo_font_map_set_default (PangoCairoFontMap *fontmap)*/
/*PangoFontMap * 	pango_cairo_font_map_new (void)*/
/*PangoFontMap * 	pango_cairo_font_map_new_for_font_type (cairo_font_type_t fonttype)*/
/*cairo_font_type_t 	pango_cairo_font_map_get_font_type (PangoCairoFontMap *fontmap)*/
/*void 	pango_cairo_font_map_set_resolution (PangoCairoFontMap *fontmap, double dpi)*/
/*double 	pango_cairo_font_map_get_resolution (PangoCairoFontMap *fontmap)*/
/*PangoContext * 	pango_cairo_font_map_create_context (PangoCairoFontMap *fontmap)*/
/*cairo_scaled_font_t * 	pango_cairo_font_get_scaled_font (PangoCairoFont *font)*/
/*void 	pango_cairo_context_set_resolution (PangoContext *context, double dpi)*/
static int _pango_cairo_context_set_resolution (lua_State* L) {
    PangoContext *context = commonGetAs(L, 1, PangoContextName, PangoContext *);
    double dpi = luaL_checknumber(L, 2);
    pango_cairo_context_set_resolution(context, dpi);
    return 0;
}
/*double 	pango_cairo_context_get_resolution (PangoContext *context)*/
/*void 	pango_cairo_context_set_font_options (PangoContext *context, const cairo_font_options_t *options)*/
/*const cairo_font_options_t * 	pango_cairo_context_get_font_options (PangoContext *context)*/
/*void 	(*PangoCairoShapeRendererFunc) ()*/
/*void 	pango_cairo_context_set_shape_renderer ()*/
/*PangoCairoShapeRendererFunc 	pango_cairo_context_get_shape_renderer ()*/
/*PangoContext * 	pango_cairo_create_context (cairo_t *cr)*/
/*void 	pango_cairo_update_context (cairo_t *cr, PangoContext *context)*/
int _pango_cairo_create_layout (lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, ContextName, cairo_t *);
    PangoLayout* result = pango_cairo_create_layout(cr);
    return commonPush(L, "p", PangoLayoutName, result);
}

int _pango_cairo_update_layout (lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, ContextName, cairo_t *);
    PangoLayout *layout = commonGetAs(L, 2, PangoLayoutName, PangoLayout *);
    pango_cairo_update_layout(cr, layout);
    return 0;
}
/*void 	pango_cairo_show_glyph_string (cairo_t *cr,
                               PangoFont *font,
                               PangoGlyphString *glyphs)*/
int _pango_cairo_show_glyph_string (lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, ContextName, cairo_t *);
    PangoFont *font = commonGetAs(L, 2, PangoFontName, PangoFont *);
    PangoGlyphString *glyphs = commonGetAs(L, 2, PangoGlyphStringName, PangoGlyphString *);
    pango_cairo_show_glyph_string(cr, font, glyphs);
    return 0;
}
/*void 	pango_cairo_show_glyph_item (cairo_t *cr,
                             const char *text,
                             PangoGlyphItem *glyph_item)*/
/*void 	pango_cairo_show_layout_line (cairo_t *cr,
                              PangoLayoutLine *line)*/
int _pango_cairo_show_layout (lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, ContextName, cairo_t *);
    PangoLayout *layout = commonGetAs(L, 2, PangoLayoutName, PangoLayout *);
    pango_cairo_show_layout(cr, layout);
    return 0;
}
/*void 	pango_cairo_show_error_underline (cairo_t *cr,
                                  double x,
                                  double y,
                                  double width,
                                  double height)*/
/*void 	pango_cairo_glyph_string_path (cairo_t *cr,
                               PangoFont *font,
                               PangoGlyphString *glyphs)*/
/*void 	pango_cairo_layout_line_path (cairo_t *cr,
                              PangoLayoutLine *line)*/
/*void 	pango_cairo_layout_path (cairo_t *cr,
                         PangoLayout *layout)*/
/*void 	pango_cairo_error_underline_path (cairo_t *cr,
                                  double x,
                                  double y,
                                  double width,
                                  double height)*/

const luaL_Reg PangoCairoFunctions[] = {
    { "getDefaultFontMap", _pango_cairo_font_map_get_default },
    { "pangoContextSetResolution", _pango_cairo_context_set_resolution },
    { NULL, NULL }
};
