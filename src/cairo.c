#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <cairo.h>
#include "common/common.h"
#include "common/table.h"

#include "context.h"
#include "path.h"
#include "text.h"
#include "surface.h"
#include "image_surface.h"


static const luaL_Reg functions[] = {
    { NULL, NULL }
};

static const struct {
    const luaL_Reg *functions;
} libraries[] = {
    { SurfaceFunctions },
    { ImageSurfaceFunctions },
    { ContextFunctions },
    { NULL }
};

static const struct {
    const char	*name;
    const CommonEnum *values;
} enums[] = {
    /* image_surface */
    { "Format", CairoFormat },
    /* context */
    { "Antialias", CairoAntialias },
    { "FillRule", CairoFillRule },
    { "LineCap", CairoLineCap },
    { "LineJoin", CairoLineJoin },
    { "Operator", CairoOperator },
    /* path */
    { "Path", CairoPath },
    /* text */
    { "FontSlant", CairoFontSlant },
    { "FontWeight", CairoFontWeight },
    /* surface */
    { "Content", CairoContent },
    { "SurfaceType", CairoSurfaceType },
    { NULL, NULL }
};

static const struct {
	const CommonObject *object;
} objects[] = {
    { &Context },
    { &Surface },
    { &ImageSurface },
    { &Context },
    { NULL }
};


int EXPORT
luaopen_Cairo(lua_State *L)
{
    /*int i;*/

    commonNewLibrary(L, functions);

    /*for (i = 0; libraries[i].functions != NULL; ++i)*/
        /*commonBindLibrary(L, libraries[i].functions);*/

    /*for (i = 0; enums[i].values != NULL; ++i)*/
        /*commonBindEnum(L, -1, enums[i].name, enums[i].values);*/

	/*for (i = 0; objects[i].object != NULL; ++i)*/
		/*commonBindObject(L, objects[i].object);*/

    return 1;
}

/*static int _wrap_cairo_version(lua_State* L) {
    int SWIG_arg = 0;
    int result;
  
    SWIG_check_num_args("cairo_version",0,0)
    result = (int)cairo_version();
    lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
    return SWIG_arg;
  
    if(0) SWIG_fail;
  
fail:
    lua_error(L);
    return SWIG_arg;
}


static int _wrap_cairo_version_string(lua_State* L) {
    int SWIG_arg = 0;
    char *result = 0 ;
  
    SWIG_check_num_args("cairo_version_string",0,0)
    result = (char *)cairo_version_string();
    lua_pushstring(L,(const char *)result); SWIG_arg++;
    return SWIG_arg;
  
    if(0) SWIG_fail;
  
fail:
    lua_error(L);
    return SWIG_arg;
}*/
