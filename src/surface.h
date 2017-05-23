#ifndef _SURFACE_H_
#define _SURFACE_H_

#include <common/common.h>
#include <common/cairo_common.h>

#define SurfaceName	Surface.name

extern const luaL_Reg SurfaceFunctions[];

extern const CommonObject Surface;

extern const CommonEnum CairoContent[];
extern const CommonEnum CairoSurfaceType[];

#endif /* !_SURFACE_H_ */
