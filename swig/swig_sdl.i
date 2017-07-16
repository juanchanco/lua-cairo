%module swig_sdl
%{
#include "SDL.h"
%}
/* va_list args */
%ignore SDL_LogMessageV;
%ignore SDL_vsscanf;
%ignore SDL_vsnprintf;
%ignore SDL_SetError;
%typemap(in) Uint32 {
  $1 = (Uint32) lua_tonumber(L, $input);
}
/*#define SDL_BUILDING_LIBRARY*/
/*#define __asm__*/
/*#define __volatile__*/
/*%include "SDL_main.h"*/
%import <SDL_config.h>
%import <begin_code.h>
%import <close_code.h>
%import <SDL_platform.h>
%import <SDL_stdinc.h>
%include <SDL_assert.h>
%include <SDL_atomic.h>
%include <SDL_audio.h>
%include <SDL_clipboard.h>
%include <SDL_cpuinfo.h>
%include <SDL_endian.h>
%include <SDL_error.h>
%include <SDL_events.h>
%include <SDL_filesystem.h>
%include <SDL_joystick.h>
%include <SDL_gamecontroller.h>
%include <SDL_haptic.h>
%include <SDL_hints.h>
%include <SDL_loadso.h>
%include <SDL_log.h>
%include <SDL_messagebox.h>
%include <SDL_mutex.h>
%include <SDL_power.h>
%include <SDL_render.h>
%include <SDL_rwops.h>
%include <SDL_system.h>
%include <SDL_thread.h>
%include <SDL_timer.h>
%include <SDL_version.h>
%include <SDL_video.h>
