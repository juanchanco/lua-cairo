#ifndef _FONT_FACE_H_
#define _FONT_FACE_H_

#include <common/common.h>

#define FontFaceName	FontFace.name

extern const CommonEnum CairoFontType[];

extern const luaL_Reg FontFaceFunctions[];

extern const CommonObject FontFace;

#endif /* _FONT_FACE_H_ */
