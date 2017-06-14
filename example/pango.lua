local Pango = require("Pango")
local Cairo = require("Cairo")
local RADIUS = 200
local N_WORDS = 8
local FONT_WITH_MANUAL_SIZE = "Times new roman,Sans"
local FONT_SIZE = 36
local DEVICE_DPI = 72
local TWEAKABLE_SCALE = 0.1
local G_PI = math.pi
local PANGO_SCALE = 1024
local draw_text = function(cr)
  cr:translate (RADIUS / TWEAKABLE_SCALE, RADIUS / TWEAKABLE_SCALE)
  local layout = cr:createPangoLayout()
  layout:setText("Test\nسَلام", -1)
  local desc = Pango.fontDescriptionFromString(FONT_WITH_MANUAL_SIZE)
  desc:setAbsoluteSize( FONT_SIZE * DEVICE_DPI * PANGO_SCALE / (72.0 * TWEAKABLE_SCALE))

  layout:setFontDescription(desc)

  for i = 0, N_WORDS do
    local angle = (360. * i) / N_WORDS
    cr:save()
    local red = (1 + math.cos ((angle - 60) * G_PI / 180.)) / 2
    cr:setSourceRgb({r=red, g=0, b=1.0 - red})
    cr:rotate(angle * G_PI / 180.)
    cr:updatePangoLayout(layout)

    local w,_ = layout:getSize()
    cr:moveTo (( - (w / PANGO_SCALE) / 2.0) , (- RADIUS)  / TWEAKABLE_SCALE)
    cr:showPangoLayout(layout)

    cr:restore()
  end
end

local filename = "test.png"
local surface = Cairo.imageSurfaceCreate(Cairo.Format.Argb32, 2 * RADIUS, 2 * RADIUS)
local cr = surface:createContext()
cr:scale(1 * TWEAKABLE_SCALE, 1 * TWEAKABLE_SCALE)
cr:setSourceRgb({r=1.0, g=1.0, b=1.0})
cr:paint()
draw_text (cr)
surface:writeToPng(filename)
