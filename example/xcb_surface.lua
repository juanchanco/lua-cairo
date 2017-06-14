local Cairo = require("Cairo")
local XCB = require("XCB")
local conn = assert(XCB.xcbConnect({}))
local screen = conn:createScreen()
local wid = conn:generateId()
local params = {
  window = wid,
  parent = screen.root,
  x = 20,
  y = 20,
  width = 150,
  height = 150,
  class = XCB.WindowClass.InputOutput,
  visual = screen.root_visual,
  mask = { XCB.CW.BackPixel, XCB.CW.EventMask },
  value0 = screen.white_pixel,
  value1 = { XCB.EventMask.Exposure, XCB.EventMask.KeyPress }
}
conn:createWindow(params)
conn:mapWindow(wid)
conn:flush()

local surface = Cairo.xcbSurfaceCreate(conn, wid, screen, 150, 150)
local cr = surface:createContext()
conn:flush()
while true do
  local evt = conn:waitForEvent()
  if (evt.response_type == XCB.EventType.Expose) then
    cr:setSourceRgb({g=1.0})
    cr:paint()
    cr:setSourceRgb({r=1.0})
    cr:moveTo(0,0)
    cr:lineTo(150,0)
    cr:lineTo(150,150)
    cr:closePath()
    cr:fill()

    cr:setSourceRgb({b=1.0})
    cr:setLineWidth(20)
    cr:moveTo(0,150)
    cr:lineTo(150,0)
    cr:stroke()
    surface:flush()
  elseif (evt.response_type == XCB.EventType.KeyPress) then
    break
  end
  conn:flush()
end
