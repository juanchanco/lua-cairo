#include <cairo.h>
#include "common.h"

#ifndef _CAIRO_COMMON_H_
#define _CAIRO_COMMON_H_

/**
 * Pushes count * nil + the SDL_GetError() message.
 *
 * @param L the Lua state
 * @param count number of nil to pushes before
 * @return count
 */
int
commonPushCairoError(lua_State *L, cairo_status_t status);

CommonUserdata *
commonGetUserdataBase(lua_State *L, int index, const char *tname);


void
commonExtendObject(lua_State *L, const CommonObject *base, const CommonObject *def);

#endif /* !_CAIRO_COMMON_H_ */
