local cairo = require("swig_cairo")
local cairo_xcb = require("swig_cairo_xcb")
local cairo_ft = require("swig_cairo_ft")

local getWDefault = function(x, d) if (x == nil) then return d else return x end end
local zeroIfNull = function(x) if (x == nil) then return 0 else return x end end

local context_metatable = {
  __gc = function(self)
    cairo.cairo_destroy(self)
  end,
  __index = {
    setSourceRgb = function(self, r, g, b)
      --local r = getWDefault(params.r, 0.0)
      --local g = getWDefault(params.g, 0.0)
      --local b = getWDefault(params.b, 0.0)
      cairo.cairo_set_source_rgb(self, r, g, b)
    end,
    setSourceRgba = function(self, r, g, b, a)
      --local r = getWDefault(params.r, 0.0)
      --local g = getWDefault(params.g, 0.0)
      --local b = getWDefault(params.b, 0.0)
      --local a = getWDefault(params.a, 0.0)
      cairo.cairo_set_source_rgb(self, r, g, b, a)
    end,
    setLineWidth = function(self, w)
      cairo.cairo_set_line_width(self, w)
    end,
    moveTo = function(self, x, y)
      cairo.cairo_move_to(self, x, y)
    end,
    lineTo = function(self, x, y)
      cairo.cairo_line_to(self, x, y)
    end,
    paint = function(self)
      cairo.cairo_paint(self)
    end,
    stroke = function(self)
      cairo.cairo_stroke(self)
    end,
    fill = function(self)
      cairo.cairo_fill(self)
    end,
    closePath = function(self)
      cairo.cairo_close_path(self)
    end,
    setFontSize = function(self, size)
      cairo.cairo_set_font_size(self, size)
    end,
    setFontFace = function(self, face)
      cairo.cairo_set_font_face(self, face)
    end,
    setFontSize = function(self, glyphs)
      cairo.cairo_show_glyphs(self, glyphs, #glyphs);
    end,
  }
}

local surface_metatable = {
  __gc = function(self)
    -- TODO: when/how to call these?
    --cairo.cairo_surface_finish(self)
    --cairo.cairo_surface_destroy(self)
  end,
  __index = {
    cairoCreate = function(self)
      local cr = cairo.cairo_create(self)
      local status = cairo.cairo_status(cr)
      if (status == cairo.CAIRO_STATUS_SUCCESS) then
        cairo.setmetatable(cr, context_metatable)
        return cr
      else
        local message = cairo.cairo_status_to_string(status)
        return nil,message
      end
    end,
    flush = function(self)
      cairo.cairo_surface_flush(self)
    end,
  }
}
if (cairo.CAIRO_HAS_PNG_FUNCTIONS > 0) then
  local writeToPng = function(self, fname)
    local status = cairo.cairo_surface_write_to_png(self, fname)
    if (status == cairo.CAIRO_STATUS_SUCCESS) then
      return true
    else
      local message = cairo.cairo_status_to_string(status)
      return nil,message
    end
  end
  surface_metatable.__index.writeToPng = writeToPng
end


local CairoFormat = {
  Invalid = cairo.CAIRO_FORMAT_INVALID,
  Argb32 = cairo.CAIRO_FORMAT_ARGB32,
  Rgb24 = cairo.CAIRO_FORMAT_RGB24,
  A8 = cairo.CAIRO_FORMAT_A8,
  A1 = cairo.CAIRO_FORMAT_A1,
  Rgb16_565 = cairo.CAIRO_FORMAT_RGB16_565,
}
local imagesSurfaceMethods = {
  getWidth = function(self)
    return cairo.cairo_image_surface_get_width(self)
  end,
  getHeight = function(self)
    return cairo.cairo_image_surface_get_height(self)
  end,
  getStride = function(self)
    return cairo.cairo_image_surface_get_stride(self)
  end,
}
local imageSurfaceCreate = function(format, width, height)
  local surface = cairo.cairo_image_surface_create(format, width, height)
end
local xcbSurfaceCreate = function(conn, wid, visual, width, height)
  local surface = cairo_xcb.cairo_xcb_surface_create(conn, wid, visual, width, height)
  cairo.setmetatable(surface, surface_metatable)
  return surface
end

local font_face_metatable = {
  __gc = function(self)
    cairo.cairo_font_face_destroy(self)
  end,
  __index = {
    fontFaceStatus = function(self)
      cairo.cairo_font_face_status(self)
    end,
  }
}

local fontFaceCreateForFtFace = function(ftFace)
  local face = cairo_ft.cairo_ft_font_face_create_for_ft_face(ft_face, 0)
  --TODO can this riff be factored out? (same as for context)
  local status = cairo.cairo_font_face_status(status)
  if (status == cairo.CAIRO_STATUS_SUCCESS) then
    cairo.setmetatable(face, font_face_metatable)
    return cr
  else
    local message = cairo.cairo_status_to_string(status)
    return nil,message
  end
end

local formatStrideForWidth = function(format, width)
  return cairo_format_stride_for_width(format, width)
end

return {
  xcbSurfaceCreate = xcbSurfaceCreate,
  fontFaceCreateForFtFace = fontFaceCreateForFtFace,
  formatStrideForWidth = formatStrideForWidth,
  findVisual = swig_cairo_xcb.find_visual,
}
