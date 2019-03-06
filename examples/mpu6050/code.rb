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

mpu = MPU6050.new
mpu.init()

while(true)
  if(mpu.read_raw_accel)
    # x2 = mpu.accel_x * mpu.accel_x
    # y2 = mpu.accel_y * mpu.accel_y
    # z2 = mpu.accel_z * mpu.accel_z
    # mag = Math.sqrt(x2 + y2 + z2)
    # mag = abs(mag - 1) # -1 Gravity
    acc_x = mpu.accel_x
    acc_y = mpu.accel_y
    acc_z = mpu.accel_z
    x = Math.atan2(acc_x, acc_z) * 360 / 2.0 / PI
    y = Math.atan2(acc_y, acc_z) * 360 / 2.0 / PI
    z = Math.atan2(acc_x, acc_y) * 360 / 2.0 / PI
    mag = Math.sqrt(x, y, z)
    puts "#{mag},#{x},#{y},#{z}"
  end
end
