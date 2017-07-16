--local pango = require("swig_pango");
local cairo = require("swig_cairo");
local SDL = require("SDL");
--local cairosdl = require("swig_cairosdl");
--local pangocairo = require("swig_pangocairo");
local WIDTH = 400
local HEIGHT = 400
local DEPTH = 32
local M_PI = math.pi

assert(SDL.init { SDL.flags.Video, SDL.flags.Timer })

local draw = function(cr)
  local t = os.date("*t", os.time())

  local seconds = t.sec * M_PI / 30
  local minutes = t.min * M_PI / 30
  local hours = t.hour * M_PI / 6

  cairo.cairo_set_source_rgb (cr, 1, 1, 1);
  cairo.cairo_paint (cr);

  cairo.cairo_set_line_cap (cr, cairo.CAIRO_LINE_CAP_ROUND);
  cairo.cairo_set_line_width (cr, 0.1);
  cairo.cairo_set_source_rgb (cr, 0, 0, 0);
  cairo.cairo_translate (cr, 0.5, 0.5);
  cairo.cairo_rc (cr, 0, 0, 0.4, 0, M_PI * 2);
  cairo.cairo_stroke (cr);

  cairo.cairo_set_source_rgba (cr, 1, 1, 1, 0.6);
  cairo.cairo_arc (cr,
              math.sin (seconds) * 0.4, -math.cos (seconds) * 0.4,
              0.05, 0, M_PI * 2);
  cairo.cairo_fill (cr);

  cairo.cairo_set_source_rgba (cr, 0.2, 0.2, 1, 0.6);
  cairo.cairo_move_to (cr, 0, 0);
  cairo.cairo_line_to (cr, math.sin (minutes) * 0.4, -math.cos (minutes) * 0.4);
  cairo.cairo_stroke (cr);

  cairo.cairo_move_to (cr, 0, 0);
  cairo.cairo_line_to (cr, math.sin (hours) * 0.2, -math.cos (hours) * 0.2);
  cairo.cairo_stroke (cr);
end

local draw_screen = function(s)
  print(1)
  s:lock()
  print(2)
  local w, h = s:getSize()
  print(3)
  local cr = cairosdl.cairosdl_create(s)
  --local cr = cairo.cairo_image_surface_create_for_data(
    --s:getPixels(),
    --cairo.CAIRO_FORMAT_RGB24,
    --w,
    --h,
    --s:getPitch()
    --)

  print(4)
  cairo.cairo_scale(cr, w, h)
  print(5)
  draw(cr)
  print(6)
  local status = cairo.cairo_status(cr)
  print(7)
  cairosdl.cairosdl_destroy(cr)
  print(8)

  if (not status == cairo.CAIRO_STATUS_SUCCESS) then
    error("draw_screen")
  end

  s:unlock()
end

--[[local timer_cb = function(interval)
  return interval
end]]

local win = assert(SDL.createWindow {
      title	= "CLOCK",
      height	= WIDTH,
      width	= HEIGHT
  }
)
local rdr = assert(SDL.createRenderer(win, 0, 0))
local surface = assert(SDL.createRGBSurface(WIDTH, HEIGHT, DEPTH))


--SDL.addTimer(100, timer_cb)

local continue = true

while continue do
  for e in SDL.pollEvent() do
    if e.type == SDL.event.Quit then
      continue = false
      break
    elseif e.type == SDL.event.KeyDown then
      if (e.key.keysym.sym == SDL.key.q) then
        continue = false
      end
      break
    else
      draw_screen(surface)
      surface = rdr:createTextureFromSurface(surface)
      rdr:clear()
      rdr:copy(surface)
      rdr:present()

      SDL.delay(100)
    end
  end
end
