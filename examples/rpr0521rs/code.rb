# -*- coding: utf-8 -*-
rc = RPR0521RS.new
rc.init

while true
  ps_als_vals = rc.get_psalsval
  puts "Proximity: #{ps_als_vals[0]} [count]"
  puts "Ambient Light: #{ps_als_vals[1]} [lx]"
  sleep(1)
end

