#ifndef _FONT_OPTIONS_H_
#define _FONT_OPTIONS_H_

#include <common/common.h>

#define FontOptionsName	FontOptions.name

extern const CommonEnum CairoSubPixelOrder[];
extern const CommonEnum CairoHintStyle[];
extern const CommonEnum CairoHintMetrics[];

extern const luaL_Reg FontOptionsFunctions[];

extern const CommonObject FontOptions;

#endif /* _FONT_OPTIONS_ */
