%module swig_cairo
%{
 #include <cairo.h>
%}
/*%include <typemaps.i>*/
/*%apply SWIGTYPE** OUTPUT { cairo_text_extents_t **extents };*/
/*#define CAIRO_HAS_PNG_FUNCTIONS 1*/
%include <carrays.i>
%array_functions(cairo_glyph_t, glyphs)
%import <cairo-features.h>
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
%inline %{
void cairo_text_extents_no_return (cairo_t *cr, const char* text) {
    cairo_text_extents_t te;
    cairo_text_extents(cr, text, &te);
}
cairo_text_extents_t* cairo_text_extents_return(cairo_t *cr, const char* text) {
    /*TODO: will swip properly free() this?*/
    cairo_text_extents_t *te = (cairo_text_extents_t*) malloc(sizeof(cairo_text_extents_t));
    cairo_text_extents(cr, text, te);
    return te;
}
%}
