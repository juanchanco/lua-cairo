local cairo = require("swig_cairo")
local cairo_xcb = require("swig_cairo_xcb")
local cairo_ft = require("swig_cairo_ft")
local cairo_gl = require("swig_cairo_gl")
local cairosdl = require("swig_cairosdl")

for k,v in pairs(cairo) do
  print(string.format("%s = %s", k, v))
  local mt = getmetatable(v)
  if (mt) then
    for x,y in pairs(mt) do
      print(string.format("  %s = %s", x, y))
    end
  end
end
print("cairo_xcb================================================")
for k,v in pairs(cairo_xcb) do
  print(string.format("%s = %s", k, v))
  local mt = getmetatable(v)
  if (mt) then
    for x,y in pairs(mt) do
      print(string.format("  %s = %s", x, y))
    end
  end
end
print("cairo_ft================================================")
for k,v in pairs(cairo_ft) do
  print(string.format("%s = %s", k, v))
  local mt = getmetatable(v)
  if (mt) then
    for x,y in pairs(mt) do
      print(string.format("  %s = %s", x, y))
    end
  end
end
print("cairo_gl================================================")
for k,v in pairs(cairo_gl) do
  print(string.format("%s = %s", k, v))
  local mt = getmetatable(v)
  if (mt) then
    for x,y in pairs(mt) do
      print(string.format("  %s = %s", x, y))
    end
  end
end
print("cairosdl================================================")
for k,v in pairs(cairosdl) do
  print(string.format("%s = %s", k, v))
  local mt = getmetatable(v)
  if (mt) then
    for x,y in pairs(mt) do
      print(string.format("  %s = %s", x, y))
    end
  end
end
