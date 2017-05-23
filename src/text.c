#include "text.h"
#include "context.h"
const CommonEnum CairoFontSlant[] = {
    { "Normal", CAIRO_FONT_SLANT_NORMAL },
    { "Italic", CAIRO_FONT_SLANT_ITALIC },
    { "Oblique", CAIRO_FONT_SLANT_OBLIQUE },
    { NULL, -1 }
};
const CommonEnum CairoFontWeight[] = {
    { "Normal", CAIRO_FONT_WEIGHT_NORMAL },
    { "Bold", CAIRO_FONT_WEIGHT_BOLD },
    { NULL, -1 }
};

int _cairo_select_font_face (lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    const char* str = luaL_checkstring (L, 2);
    int slant = commonGetEnum(L, 3);
    int weight = commonGetEnum(L, 4);
    cairo_select_font_face(cr, str, slant, weight);
    return commonPush(L, "b", 1);
}
int _cairo_set_font_size (lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    double size = (double) luaL_checknumber(L, 2);
    cairo_set_font_size(cr, size);
    return commonPush(L, "b", 1);
}
/*void 	cairo_set_font_matrix ()*/
/*void 	cairo_get_font_matrix ()*/
/*void 	cairo_set_font_options ()*/
/*void 	cairo_get_font_options ()*/
/*void 	cairo_set_font_face ()*/
/*cairo_font_face_t * 	cairo_get_font_face ()*/
/*void 	cairo_set_scaled_font ()*/
/*cairo_scaled_font_t * 	cairo_get_scaled_font ()*/
int _cairo_show_text (lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    const char* text = luaL_checkstring (L, 2);
    cairo_show_text(cr, text);
    return commonPush(L, "b", 1);
}
/*void 	cairo_show_glyphs ()*/
/*void 	cairo_show_text_glyphs ()*/
/*void 	cairo_font_extents ()*/
/*VOID 	cairo_text_extents () {}*/
/*void 	cairo_glyph_extents ()*/
/*cairo_font_face_t * 	cairo_toy_font_face_create ()*/
/*const char * 	cairo_toy_font_face_get_family ()*/
/*cairo_font_slant_t 	cairo_toy_font_face_get_slant ()*/
/*cairo_font_weight_t 	cairo_toy_font_face_get_weight ()*/
/*cairo_glyph_t * 	cairo_glyph_allocate ()*/
/*void 	cairo_glyph_free ()*/
/*cairo_text_cluster_t * 	cairo_text_cluster_allocate ()*/
/*void 	cairo_text_cluster_free ()*/

/*
#include<cairo.h>                                                                                   
#include<iostream>                                                                                  
#include<string>                                                                                    
 
using std::string;
using namespace std;
 
 
int main(int argc, char* argv[])
{                               
  int x,y,width,height;         
  float size_font;              
 
  x = 20;                       
  y = 20;                       
  width = 200;                  
  height = 40;                  
  size_font=20.0;               
  string file_path(argv[1]);    
 
 
  cairo_surface_t *surface;     
  cairo_t *cr;                  
 
 
  surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, width, height);
  cr = cairo_create (surface);
 
  cairo_text_extents_t te;
  cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
  cairo_select_font_face (cr, "Georgia",
                          CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
  cairo_set_font_size (cr, size_font);
  cairo_text_extents (cr, "hello world!", &te);
  cairo_move_to (cr, x ,y);
  cairo_show_text (cr, "hello world!");
  cairo_fill(cr);
  cairo_surface_write_to_png(surface , file_path.c_str());
 
    return 0;
}
*/
