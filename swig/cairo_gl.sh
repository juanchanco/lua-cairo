uname=`uname`
extra_pc=
if [ "$uname" = "Darwin" ]; then
        swig=swig
        extra_pc=lua5.3
elif [ "$uname" = "NetBSD" ]; then
        swig=swig3.0
else
        swig=swig3.0
fi
export PKG_CONFIG_PATH="/usr/local/lib/pkgconfig:${PKG_CONFIG_PATH}"
$swig -lua `pkg-config --cflags-only-I cairo-gl` swig_cairo_gl.i
gcc -fPIC `pkg-config --cflags cairo-gl $extra_pc` -c swig_cairo_gl_wrap.c -o swig_cairo_gl_wrap.o
gcc -shared `pkg-config --cflags --libs cairo-gl $extra_pc` swig_cairo_gl_wrap.o -o swig_cairo_gl.so
