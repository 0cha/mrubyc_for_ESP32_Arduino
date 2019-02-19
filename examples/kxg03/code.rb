# This code use the  'Math' class.
# Edit: mrubyc/src/vm_config.h
# 67: #define MRBC_USE_MATH 0
# to
# 67: #define MRBC_USE_MATH 1

PI = 3.141592653589793
def abs(val)
  if(val < 0)
    return -val;
  else
    return val;
  end
end

kxg03 = KXG03.new
kxg03.init()

while(true)
  if(kxg03.get_val())
    # puts "Gyro X: #{kxg03.gyro_x}"
    # puts "Gyro Y: #{kxg03.gyro_y}"
    # puts "Gyro Z: #{kxg03.gyro_z}"
    # puts "Accel X: #{kxg03.accel_x}"
    # puts "Accel Y: #{kxg03.accel_y}"
    # puts "Accel Z: #{kxg03.accel_z}"
    x2 = kxg03.accel_x * kxg03.accel_x
    y2 = kxg03.accel_y * kxg03.accel_y
    z2 = kxg03.accel_z * kxg03.accel_z
    mag = Math.sqrt(x2 + y2 + z2)
    mag = abs(mag - 1) # -1 Gravity
    x = Math.atan(x2/Math.sqrt(y2 + z2))*180/PI;
    y = Math.atan(y2/Math.sqrt(z2 + x2))*180/PI;
    z = Math.atan(z2/Math.sqrt(x2 + y2))*180/PI;
    puts "#{mag*100},#{x + 150},#{y + 250},#{z+350}"
  end
end
