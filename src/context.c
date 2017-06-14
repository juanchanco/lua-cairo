#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <cairo.h>
#include "common/common.h"
#include "common/table.h"

#include "context.h"
#include "path.h"
#include "transformation.h"
#include "text.h"
/*TODO: MAKE CONDITIONAL */
#include "pangocairo.h"

const CommonEnum CairoAntialias[] = {
    { "Default", CAIRO_ANTIALIAS_DEFAULT },
    { "None", CAIRO_ANTIALIAS_NONE },
    { "Gray", CAIRO_ANTIALIAS_GRAY },
    { "Subpixel", CAIRO_ANTIALIAS_SUBPIXEL },
    { "Fast", CAIRO_ANTIALIAS_FAST },
    { "Good", CAIRO_ANTIALIAS_GOOD },
    { "Best", CAIRO_ANTIALIAS_BEST },
    { NULL, -1 }
};

const CommonEnum CairoFillRule[] = {
    { "Winding", CAIRO_FILL_RULE_WINDING },
    { "Even_odd", CAIRO_FILL_RULE_EVEN_ODD },
    { NULL, -1 }
};
const CommonEnum CairoLineCap[] = {
    { "Butt", CAIRO_LINE_CAP_BUTT },
    { "Round", CAIRO_LINE_CAP_ROUND },
    { "Square", CAIRO_LINE_CAP_SQUARE },
    { NULL, -1 }
};
const CommonEnum CairoLineJoin[] = {
    { "Miter", CAIRO_LINE_JOIN_MITER },
    { "Round", CAIRO_LINE_JOIN_ROUND },
    { "Bevel", CAIRO_LINE_JOIN_BEVEL },
    { NULL, -1 }
};
const CommonEnum CairoOperator[] = {
    { "Clear", CAIRO_OPERATOR_CLEAR },
    { "Source", CAIRO_OPERATOR_SOURCE },
    { "Over", CAIRO_OPERATOR_OVER },
    { "In", CAIRO_OPERATOR_IN },
    { "Out", CAIRO_OPERATOR_OUT },
    { "Atop", CAIRO_OPERATOR_ATOP },
    { "Dest", CAIRO_OPERATOR_DEST },
    { "Dest_over", CAIRO_OPERATOR_DEST_OVER },
    { "Dest_in", CAIRO_OPERATOR_DEST_IN },
    { "Dest_out", CAIRO_OPERATOR_DEST_OUT },
    { "Dest_atop", CAIRO_OPERATOR_DEST_ATOP },
    { "Xor", CAIRO_OPERATOR_XOR },
    { "Add", CAIRO_OPERATOR_ADD },
    { "Saturate", CAIRO_OPERATOR_SATURATE },
    { "Multiply", CAIRO_OPERATOR_MULTIPLY },
    { "Screen", CAIRO_OPERATOR_SCREEN },
    { "Overlay", CAIRO_OPERATOR_OVERLAY },
    { "Darken", CAIRO_OPERATOR_DARKEN },
    { "Lighten", CAIRO_OPERATOR_LIGHTEN },
    { "Color_dodge", CAIRO_OPERATOR_COLOR_DODGE },
    { "Color_burn", CAIRO_OPERATOR_COLOR_BURN },
    { "Hard_light", CAIRO_OPERATOR_HARD_LIGHT },
    { "Soft_light", CAIRO_OPERATOR_SOFT_LIGHT },
    { "Difference", CAIRO_OPERATOR_DIFFERENCE },
    { "Exclusion", CAIRO_OPERATOR_EXCLUSION },
    { "Hsl_hue", CAIRO_OPERATOR_HSL_HUE },
    { "Hsl_saturation", CAIRO_OPERATOR_HSL_SATURATION },
    { "Hsl_color", CAIRO_OPERATOR_HSL_COLOR },
    { "Hsl_luminosity", CAIRO_OPERATOR_HSL_LUMINOSITY },
    { NULL, -1 }
};

static int _cairo_save(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    cairo_save(cr);
    return 0;
}

static int _cairo_restore(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    cairo_restore(cr);
    return 0;
}


/*TODO: version that takes a map*/
static int _cairo_set_source_rgb(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
	luaL_checktype(L, 2, LUA_TTABLE);
    double r = tableGetDouble(L, 2, "r");
    double g = tableGetDouble(L, 2, "g");
    double b = tableGetDouble(L, 2, "b");

    cairo_set_source_rgb(cr, r, g, b);
    return 0;
}

/*TODO: version that takes a map*/
static int _cairo_set_source_rgba(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
	luaL_checktype(L, 2, LUA_TTABLE);
    double r = tableGetDouble(L, 2, "r");
    double g = tableGetDouble(L, 2, "g");
    double b = tableGetDouble(L, 2, "b");
    double a = tableGetDouble(L, 2, "a");

    cairo_set_source_rgba(cr, r, g, b, a);
    return 0;
}

static int _cairo_set_line_width(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    double width = (double) luaL_checknumber(L, 2);
    cairo_set_line_width(cr, width);
    return 0;
}

static int _cairo_set_line_cap(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    int cap = commonGetEnum(L, 2);
    cairo_set_line_cap(cr, cap);
    return 0;
}

static int _cairo_stroke(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    cairo_stroke(cr);
    return 0;
}

static int _cairo_fill(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    cairo_fill(cr);
    return 0;
}

static int _cairo_paint(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    cairo_paint(cr);
    return 0;
}

static int _cairo_destroy(lua_State *L) {
    CommonUserdata *udata = commonGetUserdata(L, 1, ContextName);
    /*if (udata->mustdelete)*/
    cairo_destroy(udata->data);

    return 0;
}

const luaL_Reg ContextFunctions[] = {
    { NULL, NULL }
};
const luaL_Reg ContextMethods[] = {
    { "save", _cairo_save },
    { "restore", _cairo_restore },
    { "setSourceRgb", _cairo_set_source_rgb },
    { "setSourceRgba", _cairo_set_source_rgba },
    { "setLineWidth", _cairo_set_line_width },
    { "setLineCap", _cairo_set_line_cap },
    { "setFill", _cairo_fill },
    { "paint", _cairo_paint },
    { "stroke", _cairo_stroke },
    { "fill", _cairo_fill },
    /*path.c*/
    { "moveTo", _cairo_move_to },
    { "lineTo", _cairo_line_to },
    { "arc", _cairo_arc },
    { "closePath", _cairo_close_path },
    /*transformation.c*/
    { "translate", _cairo_translate },
    { "scale", _cairo_scale },
    { "rotate", _cairo_rotate },
    /*text.c*/
    { "selectFontFace", _cairo_select_font_face },
    { "setFontSize", _cairo_set_font_size },
    { "showText", _cairo_show_text },
    { "textExtents", _cairo_text_extents },
    /*pangocairo TODO: MAKE CONDITIONAL */
    { "createPangoLayout", _pango_cairo_create_layout },
    { "updatePangoLayout", _pango_cairo_update_layout },
    { "showPangoGlyphString", _pango_cairo_show_glyph_string },
    { "showPangoLayout", _pango_cairo_show_layout },
    { NULL, NULL }
};

const luaL_Reg ContextMetamethods[] = {
    { "__gc", _cairo_destroy },
    { NULL, NULL }
};

const CommonObject Context = {
    "Cairo.Context",
    ContextMethods,
    ContextMetamethods
};
