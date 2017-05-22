#include "cairo_common.h"

int
commonPushCairoError(lua_State *L, cairo_status_t status)
{
        lua_pushnil(L);
        lua_pushstring(L, cairo_status_to_string(status));
        return 2;
}
