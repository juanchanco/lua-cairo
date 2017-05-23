#ifndef _TEXT_
#define _TEXT_

#include <common/common.h>
#include <common/cairo_common.h>

extern const CommonEnum CairoFontSlant[];
extern const CommonEnum CairoFontWeight[];

extern int _cairo_select_font_face(lua_State* L);
extern int _cairo_set_font_size(lua_State* L);
extern int _cairo_show_text(lua_State* L);
extern int _cairo_text_extents(lua_State* L);

#endif /* !_TEXT_ */
