%module swig_cairo
%{
 #include <cairo.h>
%}
#define CAIRO_HAS_PNG_FUNCTIONS 1
%include <carrays.i>
%array_functions(cairo_glyph_t, glyphs)
%include <cairo.h>
%native(setmetatable) int userdata_set_metatable(lua_State *L);
%{
int userdata_set_metatable(lua_State *L)
{
    luaL_checktype(L, 1, LUA_TUSERDATA);
    luaL_checktype(L, 2, LUA_TTABLE);
    lua_pushvalue(L,2);
    lua_setmetatable(L,1);
    return 0;
}
%}
