#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <cairo.h>
#include "common/common.h"
#include "common/table.h"

const CommonEnum CairoFormat[] = {
  { "Invalid", CAIRO_FORMAT_INVALID },
  { "Argb32", CAIRO_FORMAT_ARGB32 },
  { "Rgb24", CAIRO_FORMAT_RGB24 },
  { "A8", CAIRO_FORMAT_A8 },
  { "A1", CAIRO_FORMAT_A1 },
  { "Rgb16_565", CAIRO_FORMAT_RGB16_565 },
  { NULL, -1 }
};

static int _cairo_image_surface_create(lua_State* L) {
  int format = commonGetEnum(L, 1);
  int width = luaL_checkinteger(L, 2);
  int height = luaL_checkinteger(L, 3);
  cairo_surface_t* result = cairo_image_surface_create(format, width, height);
  return commonPush(L, "p", "Surface", result);
}

static const luaL_Reg functions[] = {
  { "imageSurfaceCreate", _cairo_image_surface_create },
  { NULL, NULL }
};


static const struct {
	const luaL_Reg *functions;
} libraries[] = {
	/*{ CpuFunctions					},*/
	{ NULL						}
};

static const struct {
	const char	*name;
	const CommonEnum *values;
} enums[] = {
	{ "cairoFormat", CairoFormat },
	{ NULL, NULL }
};


int EXPORT
luaopen_SDL(lua_State *L)
{
	int i;

	/* General functions */
	commonNewLibrary(L, functions);

	/* Library categories */
	for (i = 0; libraries[i].functions != NULL; ++i)
		commonBindLibrary(L, libraries[i].functions);

	/* Enumerations */
	for (i = 0; enums[i].values != NULL; ++i)
		commonBindEnum(L, -1, enums[i].name, enums[i].values);

	/* Object oriented data */
	/*for (i = 0; objects[i].object != NULL; ++i)*/
		/*commonBindObject(L, objects[i].object);*/

	/* Store the version */
	/*cairo_version ver;*/
	/*SDL_GetVersion(&ver);*/

	/*tableSetInt(L, -1, "VERSION_MAJOR", ver.major);*/
	/*tableSetInt(L, -1, "VERSION_MINOR", ver.minor);*/
	/*tableSetInt(L, -1, "VERSION_PATCH", ver.patch);*/

	tableSetInt(L, -1, "VERSION_BINDING", 4);
	tableSetInt(L, -1, "VERSION_BINDING_PATCH", 1);

	/*lua_newtable(L);*/
	/*tableSetInt(L, -1, "major", ver.major);*/
	/*tableSetInt(L, -1, "minor", ver.minor);*/
	/*tableSetInt(L, -1, "patch", ver.patch);*/
	/*lua_setfield(L, -2, "version");*/

	lua_newtable(L);
	tableSetInt(L, -1, "major", VERSION_BINDING_MAJOR);
	tableSetInt(L, -1, "minor", VERSION_BINDING_MINOR);
	lua_setfield(L, -2, "binding");

	return 1;
}
