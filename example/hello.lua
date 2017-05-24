local Cairo = require("Cairo")
 
local x = 20
local y = 20
local width = 200
local height = 40
local size_font=20.0
local fname = "hello.png"

local surface = Cairo.imageSurfaceCreate(Cairo.Format.Argb32, width, height)
local cr = surface:createContext()
cr:setSourceRgb(0.0, 0.0, 0.0)
cr:selectFontFace("Georgia", Cairo.FontSlant.Normal, Cairo.FontWeight.Bold)
cr:setFontSize(size_font)
cr:textExtents("hello world")
cr:moveTo(x,y)
cr:showText("hello world")
cr:fill()
surface:writeToPng(fname)
