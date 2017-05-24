local Cairo = require("Cairo")
local conn = Cairo.xcbConnect({})
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
  visual_mask = {Cairo.XcbCW.OverrideRedirect, Cairo.XcbCW.EventMask }
}
conn:createWindow(params)
conn:mapWindow(wid)
conn:flush()

local visual = conn:findVisual(screen.rootVisual)

local surface = Cairo.xcbSurfaceCreate(conn, wid, visual, 150, 150)
