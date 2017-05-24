#ifndef _TRANSFORMATION_
#define _TRANSFORMATION_

#include <cairo.h>
#include "common/common.h"

extern int _cairo_translate(lua_State* L);
extern int _cairo_scale(lua_State* L);
extern int _cairo_rotate(lua_State* L);

#endif /* !_TRANSFORMATION_ */
