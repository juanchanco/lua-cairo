#ifndef _IMAGE_SURFACE_H_
#define _IMAGE_SURFACE_H_

#include <common/common.h>
#include <common/cairo_common.h>

#define ImageSurfaceName	ImageSurface.name

extern const luaL_Reg ImageSurfaceFunctions[];

extern const CommonObject ImageSurface;

extern const CommonEnum CairoFormat[];

#endif /* !_IMAGE_SURFACE_H_ */

