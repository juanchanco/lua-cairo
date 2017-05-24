#ifndef _XCB_CONNECTION_
#define _XCB_CONNECTION_

#include <common/common.h>
#include <common/cairo_common.h>

#define XcbConnectionName	XcbConnection.name

extern const luaL_Reg XcbConnectionFunctions[];

extern const CommonObject XcbConnection;

extern const CommonEnum XcbConnectionError[];
extern const CommonEnum XcbWindowClass[];
extern const CommonEnum XcbCW[];

#endif /* !_XCB_CONNECTION_ */
