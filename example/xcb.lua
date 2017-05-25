local Cairo = require("Cairo")
local conn = assert(Cairo.xcbConnect({}))
local screen = conn:createScreen()
local wid = conn:generateId()
local params = {
  window = wid,
  parent = screen.root,
  x = 20,
  y = 20,
  width = 150,
  height = 150,
  class = Cairo.XcbWindowClass.InputOutput,
  visual = screen.rootVisual,
  value_mask = {Cairo.XcbCW.OverrideRedirect, Cairo.XcbCW.EventMask }
}
conn:createWindow(params)
conn:mapWindow(wid)
conn:flush()

local visual = assert(conn:findVisual(screen.rootVisual))
local surface = Cairo.xcbSurfaceCreate(conn, wid, visual, 150, 150)
local cr = surface:createContext()
conn:flush()
while true do
local evt = conn:waitForEvent()
if (evt:getResonseType() == Cairo.XcbDefines.Expose) then
cr:setSourceRgb(0.0, 1.0, 0.0)
cr:paint()
cr:setSourceRgb(1.0, 0.0, 0.0)
cr:moveTo(0,0)
cr:lineTo(150,0)
cr:lineTo(150,150)
cr:closePath()
cr:fill()

cr:setSourceRgb(0.0, 0.0, 1.0)
cr:setLineWidth(20)
cr:moveTo(0,150)
cr:lineTo(150,0)
cr:stroke()
surface:flush()
elseif (evt:getResonseType() == Cairo.XcbDefines.KeyPress) then
  break
end
conn:flush()
end
