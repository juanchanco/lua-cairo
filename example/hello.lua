local Cairo = require("Cairo")

local x = 20
local y = 20
local width = 200
local height = 40
local size_font=20.0
local fname = "hello.png"

local surface = Cairo.imageSurfaceCreate(Cairo.Format.Argb32, width, height)
local cr = surface:createContext()
cr:setSourceRgb({r=1.0, g=1.0, b=1.0})
cr:paint()
cr:setSourceRgb({r=0.0, g=0.0, b=0.0})
cr:selectFontFace("Georgia", Cairo.FontSlant.Normal, Cairo.FontWeight.Bold)
cr:setFontSize(size_font)
cr:textExtents("hello world")
cr:moveTo(x,y)
cr:showText("hello world")
cr:fill()
surface:writeToPng(fname)
