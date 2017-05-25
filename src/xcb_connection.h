#ifndef _XCB_CONNECTION_
#define _XCB_CONNECTION_

#include <common/common.h>
#include <common/cairo_common.h>

#define XcbVisualName	XcbVisual.name
#define XcbEventName	XcbEvent.name
#define XcbConnectionName	XcbConnection.name

extern const luaL_Reg XcbConnectionFunctions[];

extern const CommonObject XcbVisual;
extern const CommonObject XcbEvent;
extern const CommonObject XcbConnection;

extern const CommonEnum XcbConnectionError[];
extern const CommonEnum XcbWindowClass[];
extern const CommonEnum XcbCW[];
extern const CommonEnum XcbDefines[];
extern const CommonEnum XcbEventMask[];

#endif /* !_XCB_CONNECTION_ */
