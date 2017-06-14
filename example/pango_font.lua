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
for i,v in iter(families) do
  print(string.format("(%i,%s)", i, v:getName()))
end
