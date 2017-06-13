#include <cairo.h>
#include "context.h"
#include "image_surface.h"

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
    cairo_status_t status = cairo_surface_status(result);
    if (status != CAIRO_STATUS_SUCCESS) {
        return commonPushCairoError(L, status);
    }
    return commonPush(L, "p", ImageSurfaceName, result);
}

static int _cairo_image_surface_create_for_data(lua_State* L) {
    /*TODO: make this plan old lua_userdata*/
    CommonUserdata* data = commonGetUserdata(L, 1, "Raw");
    int format = commonGetEnum(L, 2);
    int width = luaL_checkinteger(L, 3);
    int height = luaL_checkinteger(L, 4);
    int stride = luaL_checkinteger(L, 5);
    cairo_surface_t* result =
        cairo_image_surface_create_for_data(data->data, format, width, height, stride);
    cairo_status_t status = cairo_surface_status(result);
    if (status != CAIRO_STATUS_SUCCESS) {
        return commonPushCairoError(L, status);
    }
    return commonPush(L, "p", ImageSurfaceName, result);

}
static int _cairo_image_surface_get_data(lua_State* L) {
    CommonUserdata* surface = commonGetUserdata(L, 1, ImageSurfaceName);
    unsigned char* result = cairo_image_surface_get_data(surface->data);
    /*TODO: turns out the name will need to be "registered" (CommonBindObjt) */
    return commonPush(L, "p", "Raw", result);
}

static int _cairo_image_surface_get_format(lua_State* L) {
    CommonUserdata* surface = commonGetUserdata(L, 1, ImageSurfaceName);
    cairo_format_t result = cairo_image_surface_get_format(surface->data);
    /*commonPushEnum(L, result, CairoFormat);*/
    return commonPush(L, "i", result);
}


static int _cairo_image_surface_get_width(lua_State* L) {
    CommonUserdata* surface = commonGetUserdata(L, 1, ImageSurfaceName);
    int result = cairo_image_surface_get_width(surface->data);
    return commonPush(L, "i", result);
}
static int _cairo_image_surface_get_height(lua_State* L) {
    CommonUserdata* surface = commonGetUserdata(L, 1, ImageSurfaceName);
    int result = cairo_image_surface_get_height(surface->data);
    return commonPush(L, "i", result);
}

/*TODO: figure out how to make ImageSurface inherit from Surface*/
static int _cairo_image_surface_get_stride(lua_State* L) {
    CommonUserdata* surface = commonGetUserdata(L, 1, ImageSurfaceName);
    int result = cairo_image_surface_get_stride(surface->data);
    return commonPush(L, "i", result);
}

static int _cairo_format_stride_for_width(lua_State* L) {
    int format = commonGetEnum(L, 1);
    int width = luaL_checkinteger(L, 2);
    int result = cairo_format_stride_for_width(format, width);
    return commonPush(L, "i", result);
}

const luaL_Reg ImageSurfaceFunctions[] = {
    { "imageSurfaceCreate", _cairo_image_surface_create },
    { "imageSurfaceCreateForData", _cairo_image_surface_create_for_data },
    { "getStrideForWidth", _cairo_format_stride_for_width },
    { NULL, NULL }
};


static const luaL_Reg methods[] = {
    { "getData", _cairo_image_surface_get_data },
    { "getFormat", _cairo_image_surface_get_format },
    { "getWidth", _cairo_image_surface_get_width },
    { "getHeight", _cairo_image_surface_get_height },
    { "getStride", _cairo_image_surface_get_stride },
    { NULL, NULL }
};


static const luaL_Reg metamethods[] = {
    { NULL, NULL }
};


const CommonObject ImageSurface = {
    "Cairo.Surface.Image",
    methods,
    metamethods
};
