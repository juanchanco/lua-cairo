local Pango = require("Pango")
local Cairo = require("Cairo")
local map = Cairo.getDefaultFontMap()
local families = map:listFamilies()
print(#families)
local iter = function(m)
  local i = 0
  local f = function()
    i = i + 1
    local v = m[i]
    if (v) then
      return i,m[i]
    else
      return nil
    end
  end
  return f
end
for _,v in iter(families) do
  print(v)
  local faces = v:listFaces()
  for _, f in iter(faces) do
    if (f:isSynthesized()) then
      print(string.format("  %s (synthesized)", f))
    else
      print(string.format("  %s", f))
    end
    local sizes = f:listSizes()
    if (sizes) then
      for _,s in ipairs(sizes) do
        print(string.format("      Size: %f", Pango.unitsToDouble(s)))
      end
    end
  end
end
