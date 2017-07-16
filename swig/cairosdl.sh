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
$swig -lua `pkg-config --cflags-only-I cairo sdl2` swig_cairosdl.i
gcc -fPIC `pkg-config --cflags cairo sdl2` -c cairosdl.c -o cairosdl.o
gcc -fPIC `pkg-config --cflags cairo sdl2 $extra_pc` -c swig_cairosdl_wrap.c -o swig_cairosdl_wrap.o
gcc -shared `pkg-config --cflags --libs cairo sdl2 $extra_pc` cairosdl.o swig_cairosdl_wrap.o -o swig_cairosdl.so
