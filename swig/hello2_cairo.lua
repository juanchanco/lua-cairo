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
print(screen.root_visual)
local visual = cairo.findVisual(conn, screen.root_visual)
local surface = cairo.xcbSurfaceCreate(conn, window.id, visual, 150, 150)
local cr = surface:cairoCreate()
conn:flush()
conn:disconnect()
