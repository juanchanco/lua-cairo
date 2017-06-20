local cairo = require("swig_cairo")
local cairo_xcb = require("swig_cairo_xcb")

local getWDefault = function(x, d) if (x == nil) then return d else return x end end
local zeroIfNull = function(x) if (x == nil) then return 0 else return x end end

local context_metatable = {
  __gc = function(self)
    cairo.cairo_destroy(self)
  end,
  __index = {
    setSourceRgb = function(self, params)
      local r = getWDefault(params.r, 0.0)
      local g = getWDefault(params.g, 0.0)
      local b = getWDefault(params.b, 0.0)
      cairo.cairo_set_source_rgb(self, r, g, b)
    end,
    setSourceRgba = function(self, params)
      local r = getWDefault(params.r, 0.0)
      local g = getWDefault(params.g, 0.0)
      local b = getWDefault(params.b, 0.0)
      local a = getWDefault(params.a, 0.0)
      cairo.cairo_set_source_rgb(self, r, g, b, a)
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
  }
}

local surface_metatable = {
  __gc = function(self)
    cairo.cairo_surface_finish(self)
    cairo.cairo_surface_destroy(self)
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

local xcbSurfaceCreate = function(conn, wid, visual, width, height)
  local surface = cairo_xcb.cairo_xcb_surface_create(conn, wid, visual, width, height)
  cairo.setmetatable(surface, surface_metatable)
  return surface
end

return {
  xcbSurfaceCreate = xcbSurfaceCreate,
  findVisual = swig_cairo_xcb.find_visual,
}
