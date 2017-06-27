local pango = require("pango")
local cairo = require("cairo")
local RADIUS = 200
local N_WORDS = 8
local FONT_WITH_MANUAL_SIZE = "Times new roman,Sans"
local FONT_SIZE = 36
local DEVICE_DPI = 72
--local TWEAKABLE_SCALE = 0.1
local G_PI = math.pi
local PANGO_SCALE = 1024
local draw_text = function(cr)
  cr:translate (RADIUS, RADIUS)
  local layout = pango.PangoCairo.createPangoLayout(cr)
  layout:setText("Test\nسَلام", -1)
  local desc = pango.Font.fontDescriptionFromString(FONT_WITH_MANUAL_SIZE)
  desc:setAbsoluteSize( FONT_SIZE * DEVICE_DPI * PANGO_SCALE / (72.0))

  local w,_ = layout:getSize()
  layout:setFontDescription(desc)

  for i = 0, N_WORDS do
    local angle = (360. * i) / N_WORDS
    cr:save()
    local red = (1 + math.cos ((angle - 60) * G_PI / 180.)) / 2
    cr:setSourceRgb(red, 0.0, 1.0 - red)
    cr:rotate(angle * G_PI / 180.)
    pango.PangoCairo.updatePangoLayout(cr, layout)

    cr:moveTo (( - (w / PANGO_SCALE) / 2.0) , (- RADIUS))
    pango.PangoCairo.showPangoLayout(cr, layout)

    cr:restore()
  end
end

--local filename = "test.png"
--local surface = cairo.imageSurfaceCreate(cairo.Format.Argb32, 2 * RADIUS, 2 * RADIUS)
--local cr = surface:cairoCreate()
--cr:scale(1 * TWEAKABLE_SCALE, 1 * TWEAKABLE_SCALE)
--cr:setSourceRgb(1.0, 100.0, 1.0)
--cr:paint()
--draw_text (cr)
----surface:flush()
--surface:writeToPng(filename)

local xcb = require("xcb")
local conn = xcb.connect()
local screen = conn:getSetup():setupRootsIterator().data

local window = conn:createWindow({
  parent=screen.root,
  visual=screen.root_visual,
  x=20, y=20, w=450, h=450, border=10,
  class = xcb.WindowClass.InputOutput,
  mask=xcb.CW.BackPixel | xcb.CW.EventMask,
  value0=screen.white_pixel,
  value1=xcb.EventMask.Exposure | xcb.EventMask.KeyPress
})
conn:mapWindow(window)
conn:flush()
local visual = cairo.findVisual(conn, screen.root_visual)
local surface = cairo.xcbSurfaceCreate(conn, window.id, visual, 450, 450)
local cr = surface:cairoCreate()
--cr:scale(1 * TWEAKABLE_SCALE, 1 * TWEAKABLE_SCALE)
conn:flush()

local e = conn:waitForEvent()
while (e) do
  local response_type = e.response_type
  if (response_type == xcb.EventType.Expose) then
    cr:setSourceRgb(.9, .9, .9)
    cr:paint()
    draw_text (cr)
    surface:flush()
    conn:flush()
  elseif (response_type == xcb.EventType.KeyPress) then
    break
  elseif (response_type == 0) then
    if (e.error_code) then
      print(string.format("Event error code:%i", e.error_code))
    else
      print("Event error code:null")
    end
  end
  e = conn:waitForEvent()
end
conn:disconnect()
