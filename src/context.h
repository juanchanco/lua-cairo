#ifndef _LAYOUT_H_
#define _LAYOUT_H_

#include <common/common.h>

#define ContextName	Context.name

extern const luaL_Reg ContextFunctions[];

extern const CommonObject Context;

extern const CommonEnum CairoAntialias[];
extern const CommonEnum CairoFillRule[];
extern const CommonEnum CairoLineCap[];
extern const CommonEnum CairoLineJoin[];
extern const CommonEnum CairoOperator[];
 
#endif /* !_LAYOUT_H_ */
