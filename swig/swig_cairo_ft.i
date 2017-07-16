%module swig_cairo_ft
%{
 #include <cairo.h>
 #include <cairo-ft.h>
%}
/* torturous sequences of typedefs */
%import "freetype.hh"
%import <cairo.h>
%import <cairo-features.h>
%include <cairo-ft.h>
