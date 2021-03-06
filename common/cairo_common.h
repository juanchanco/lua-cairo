#include <cairo.h>
#include "common.h"

#ifndef _CAIRO_COMMON_H_
#define _CAIRO_COMMON_H_

int
commonPushCairoError(lua_State *L, cairo_status_t status);

CommonUserdata *
commonGetUserdataBase(lua_State *L, int index, const char *tname);


void
commonExtendObject(lua_State *L, const CommonObject *base, const CommonObject *def);

#endif /* !_CAIRO_COMMON_H_ */
