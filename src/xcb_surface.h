#ifndef _XCB_SURFACE_H_
#define _XCB_SURFACE_H_

#include <xcb/xcb.h>
#include <cairo-xcb.h>
//#include <stdio.h>
#include <stdlib.h>
#include "common/common.h"
#include "common/cairo_common.h"

#define XcbSurfaceName	XcbSurface.name

extern const luaL_Reg XcbSurfaceFunctions[];

extern const CommonObject XcbSurface;

extern const CommonEnum CairoFormat[];

#endif /* !_XCB_SURFACE_H_ */


