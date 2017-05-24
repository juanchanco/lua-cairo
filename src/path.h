#ifndef _PATH_
#define _PATH_

#include <common/common.h>
#include <common/cairo_common.h>

#define PathName	Path.name

extern int _cairo_move_to(lua_State* L);
extern int _cairo_line_to(lua_State* L);
extern int _cairo_arc(lua_State* L);
extern int _cairo_close_path(lua_State* L);

extern const luaL_Reg PathFunctions[];

extern const CommonObject Path;

extern const CommonEnum CairoPath[];

#endif /* !_PATH_ */
