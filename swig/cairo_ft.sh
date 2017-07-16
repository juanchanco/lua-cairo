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
$swig -lua `pkg-config --cflags-only-I cairo freetype2` swig_cairo_ft.i
gcc -fPIC `pkg-config --cflags cairo freetype2 $extra_pc` -c swig_cairo_ft_wrap.c -o swig_cairo_ft_wrap.o
gcc -shared `pkg-config --libs cairo freetype2 $extra_pc` swig_cairo_ft_wrap.o -o swig_cairo_ft.so
