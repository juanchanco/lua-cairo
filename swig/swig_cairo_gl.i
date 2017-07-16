%module swig_cairo_gl
%{
 #include <cairo.h>
 #include <cairo-gl.h>
%}
%import <cairo.h>
%import <cairo-features.h>
%include <cairo-gl.h>
