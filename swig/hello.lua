local cairo = require("cairo")

local x = 20
local y = 20
local width = 200
local height = 40
local size_font=20.0
local fname = "hello.png"

local surface = cairo.imageSurfaceCreate(cairo.Format.Argb32, width, height)
local cr = surface:cairoCreate()
cr:setSourceRgb(1.0, 1.0, 1.0)
cr:paint()
cr:setSourceRgb(0.0, 0.0, 0.0)
cr:selectFontFace("Georgia", cairo.FontSlant.Normal, cairo.FontWeight.Bold)
cr:setFontSize(size_font)
local te = cr:textExtents("hello world")
cr:moveTo(x,y)
cr:showText("hello world")
cr:fill()
surface:writeToPng(fname)
