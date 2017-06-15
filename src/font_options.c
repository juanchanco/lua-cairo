#include <stdio.h>
#include <stdlib.h>

#include <pango/pango.h>
#include <cairo.h>
#include "common/common.h"
#include "common/table.h"

#include "font_options.h"

const CommonEnum CairoSubPixelOrder[] = {
    { "Default", CAIRO_SUBPIXEL_ORDER_DEFAULT },
    { "Rgb", CAIRO_SUBPIXEL_ORDER_RGB },
    { "Bgr", CAIRO_SUBPIXEL_ORDER_BGR },
    { "Vrgb", CAIRO_SUBPIXEL_ORDER_VRGB },
    { "Vbgr", CAIRO_SUBPIXEL_ORDER_VBGR },
    { NULL, -1 }
};
const CommonEnum CairoHintStyle[] = {
    { "Default", CAIRO_HINT_STYLE_DEFAULT },
    { "None", CAIRO_HINT_STYLE_NONE },
    { "Slight", CAIRO_HINT_STYLE_SLIGHT },
    { "Medium", CAIRO_HINT_STYLE_MEDIUM },
    { "Full", CAIRO_HINT_STYLE_FULL },
    { NULL, -1 }
};
const CommonEnum CairoHintMetrics[] = {
    { "Default", CAIRO_HINT_METRICS_DEFAULT },
    { "Off", CAIRO_HINT_METRICS_OFF },
    { "On", CAIRO_HINT_METRICS_ON },
    { NULL, -1 }
};

/*cairo_font_options_t * 	cairo_font_options_create ()*/
/*cairo_font_options_t * 	cairo_font_options_copy ()*/
/*void 	cairo_font_options_destroy ()*/
/*cairo_status_t 	cairo_font_options_status ()*/
/*void 	cairo_font_options_merge ()*/
/*unsigned long 	cairo_font_options_hash ()*/
/*cairo_bool_t 	cairo_font_options_equal ()*/
/*void 	cairo_font_options_set_antialias ()*/
/*cairo_antialias_t 	cairo_font_options_get_antialias ()*/
/*void 	cairo_font_options_set_subpixel_order ()*/
/*cairo_subpixel_order_t 	cairo_font_options_get_subpixel_order ()*/
/*void 	cairo_font_options_set_hint_style ()*/
/*cairo_hint_style_t 	cairo_font_options_get_hint_style ()*/
/*void 	cairo_font_options_set_hint_metrics ()*/
/*cairo_hint_metrics_t 	cairo_font_options_get_hint_metrics ()*/

static int _cairo_font_options_create(lua_State *L) {
    cairo_font_options_t* new = cairo_font_options_create();

    return commonPush(L, "p", FontOptionsName, new);
}
static int _cairo_font_options_copy(lua_State *L) {
    cairo_font_options_t* options = commonGetAs(L, 1, FontOptionsName, cairo_font_options_t *);
    cairo_font_options_t* copy = cairo_font_options_copy(options);

    return commonPush(L, "p", FontOptionsName, copy);
}
static int _cairo_font_options_destroy(lua_State *L) {
    cairo_font_options_t* options = commonGetAs(L, 1, FontOptionsName, cairo_font_options_t *);
    cairo_font_options_destroy(options);

    return 0;
}


const luaL_Reg FontOptionsFunctions[] = {
    { "fontOptionsCreate", _cairo_font_options_create },
    { NULL, NULL }
};

static const luaL_Reg methods[] = {
    { "copy", _cairo_font_options_copy },
    { NULL, NULL }
};

static const luaL_Reg metamethods[] = {
    { "__gc", _cairo_font_options_destroy },
    { NULL, NULL }
};

const CommonObject FontOptions = {
    "Cairo.FontOptions",
    methods,
    metamethods
};
