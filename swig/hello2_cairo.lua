local cairo = require("cairo")
local xcb = require("xcb")

local conn = xcb.connect()
local screen = conn:getSetup():setupRootsIterator().data

local window = conn:createWindow({
  parent=screen.root,
  visual=screen.root_visual,
  x=20, y=20, w=150, h=150, border=10,
  class = xcb.WindowClass.InputOutput,
  mask=xcb.CW.BackPixel | xcb.CW.EventMask,
  value0=screen.white_pixel,
  value1=xcb.EventMask.Exposure | xcb.EventMask.KeyPress
})
conn:mapWindow(window)
conn:flush()
local visual = cairo.findVisual(conn, screen.root_visual)
local surface = cairo.xcbSurfaceCreate(conn, window.id, visual, 150, 150)
local cr = surface:cairoCreate()
conn:flush()

local e = conn:waitForEvent()
while (e) do
  local response_type = e.response_type
  if (response_type == xcb.EventType.Expose) then
    cr:setSourceRgb(0.0, 1.0, 0.0)
    cr:paint()
    cr:setSourceRgb(1.0, 0.0, 0.0)
    cr:moveTo(0,0)
    cr:lineTo(150, 0)
    cr:lineTo(150, 150)
    cr:closePath()
    cr:fill()

    cr:setSourceRgb(0.0, 0.0, 1.0)
    cr:setLineWidth(20)
    cr:moveTo(0, 150)
    cr:lineTo(150, 0)
    cr:stroke()
    surface:flush()
    conn:flush()
  elseif (response_type == xcb.EventType.KeyPress) then
    break
  elseif (response_type == 0) then
    print(string.format("Event error code:%i", e.error_code))
  end
  e = conn:waitForEvent()
end
conn:disconnect()
