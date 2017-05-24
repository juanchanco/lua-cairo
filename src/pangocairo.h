#ifndef _PANGOCAIRO_H_
#define _PANGOCAIRO_H_
#include <stdio.h>
#include <stdlib.h>

#include <pango/pangocairo.h>
#include "common/common.h"
#include "common/table.h"

extern int _pango_cairo_create_layout (lua_State* L);
extern int _pango_cairo_update_layout (lua_State* L);
extern int _pango_cairo_show_layout (lua_State* L);

#endif /* !_PANGOCAIRO_H_ */
