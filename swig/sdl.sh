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
$swig -lua `pkg-config --cflags-only-I sdl2` swig_sdl.i
gcc -fPIC `pkg-config --cflags sdl2 $extra_pc` -c swig_sdl_wrap.c -o swig_sdl_wrap.o
gcc -shared `pkg-config --cflags --libs sdl2 $extra_pc` swig_sdl_wrap.o -o swig_sdl.so
