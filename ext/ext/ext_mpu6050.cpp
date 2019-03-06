/******************
 Dependent: jarzebski Arduino Library MPU6050
 https://github.com/jarzebski/Arduino-MPU6050
******************/
#include "mrubyc_for_ESP32_Arduino.h"
#ifdef USE_MPU6050
#include "Arduino.h"
#include <MPU6050.h>
#include "ext.h"
MPU6050 mpu;
float gx,gy,gz,ax,ay,az;

static void class_mpu6050_init(mrb_vm *vm, mrb_value *v, int argc){
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }
  mpu.calibrateGyro();
  mpu.setThreshold(3);
}

static void class_mpu6050_check_setting(mrb_vm *vm, mrb_value *v, int argc){
  Serial.println();
  Serial.print(" * Sleep Mode:        ");
  Serial.println(mpu.getSleepEnabled() ? "Enabled" : "Disabled");
  
  Serial.print(" * Clock Source:      ");
  switch(mpu.getClockSource())
  {
    case MPU6050_CLOCK_KEEP_RESET:     Serial.println("Stops the clock and keeps the timing generator in reset"); break;
    case MPU6050_CLOCK_EXTERNAL_19MHZ: Serial.println("PLL with external 19.2MHz reference"); break;
    case MPU6050_CLOCK_EXTERNAL_32KHZ: Serial.println("PLL with external 32.768kHz reference"); break;
    case MPU6050_CLOCK_PLL_ZGYRO:      Serial.println("PLL with Z axis gyroscope reference"); break;
    case MPU6050_CLOCK_PLL_YGYRO:      Serial.println("PLL with Y axis gyroscope reference"); break;
    case MPU6050_CLOCK_PLL_XGYRO:      Serial.println("PLL with X axis gyroscope reference"); break;
    case MPU6050_CLOCK_INTERNAL_8MHZ:  Serial.println("Internal 8MHz oscillator"); break;
  }
  
  Serial.print(" * Gyroscope:         ");
  switch(mpu.getScale())
  {
    case MPU6050_SCALE_2000DPS:        Serial.println("2000 dps"); break;
    case MPU6050_SCALE_1000DPS:        Serial.println("1000 dps"); break;
    case MPU6050_SCALE_500DPS:         Serial.println("500 dps"); break;
    case MPU6050_SCALE_250DPS:         Serial.println("250 dps"); break;
  } 
  
  Serial.print(" * Gyroscope offsets: ");
  Serial.print(mpu.getGyroOffsetX());
  Serial.print(" / ");
  Serial.print(mpu.getGyroOffsetY());
  Serial.print(" / ");
  Serial.println(mpu.getGyroOffsetZ());
  
  Serial.println();
}
static void class_mpu6050_read_raw_gyro(mrb_vm *vm, mrb_value *v, int argc){
  Vector rawGyro = mpu.readRawGyro();
  gx = rawGyro.XAxis;
  gy = rawGyro.YAxis;
  gz = rawGyro.ZAxis;
  SET_TRUE_RETURN();
}

static void class_mpu6050_read_normalize_gyro(mrb_vm *vm, mrb_value *v, int argc){
  Vector normGyro = mpu.readNormalizeGyro();
  gx = normGyro.XAxis;
  gy = normGyro.YAxis;
  gz = normGyro.ZAxis;
  SET_TRUE_RETURN();
}

static void class_mpu6050_read_raw_accel(mrb_vm *vm, mrb_value *v, int argc){
  Vector rawAccel = mpu.readRawAccel();
  ax = rawAccel.XAxis;
  ay = rawAccel.YAxis;
  az = rawAccel.ZAxis;
  SET_TRUE_RETURN();
}

static void class_mpu6050_read_normalize_accel(mrb_vm *vm, mrb_value *v, int argc){
  Vector normAccel = mpu.readNormalizeAccel();
  ax = normAccel.XAxis;
  ay = normAccel.YAxis;
  az = normAccel.ZAxis;
  SET_TRUE_RETURN();
}

static void class_mpu6050_gyro_x(mrb_vm *vm, mrb_value *v, int argc){
  SET_FLOAT_RETURN(gx);
}
static void class_mpu6050_gyro_y(mrb_vm *vm, mrb_value *v, int argc){
  SET_FLOAT_RETURN(gy);
}
static void class_mpu6050_gyro_z(mrb_vm *vm, mrb_value *v, int argc){
  SET_FLOAT_RETURN(gz);
}
static void class_mpu6050_accel_x(mrb_vm *vm, mrb_value *v, int argc){
  SET_FLOAT_RETURN(ax);
}
static void class_mpu6050_accel_y(mrb_vm *vm, mrb_value *v, int argc){
  SET_FLOAT_RETURN(ay);
}
static void class_mpu6050_accel_z(mrb_vm *vm, mrb_value *v, int argc){
  SET_FLOAT_RETURN(az);
}

void define_mpu6050_class(void){
  mrb_class *class_mpu6050;
  class_mpu6050 = mrbc_define_class(0, "MPU6050", mrbc_class_object);
  mrbc_define_method(0, class_mpu6050, "init", class_mpu6050_init);
  mrbc_define_method(0, class_mpu6050, "read_raw_accel", class_mpu6050_read_raw_accel);
  mrbc_define_method(0, class_mpu6050, "read_normalize_accel", class_mpu6050_read_normalize_accel);  
  mrbc_define_method(0, class_mpu6050, "accel_x", class_mpu6050_accel_x);
  mrbc_define_method(0, class_mpu6050, "accel_y", class_mpu6050_accel_y);
  mrbc_define_method(0, class_mpu6050, "accel_z", class_mpu6050_accel_z);
  
  mrbc_define_method(0, class_mpu6050, "read_raw_gyro", class_mpu6050_read_raw_gyro);
  mrbc_define_method(0, class_mpu6050, "read_normalize_gyro", class_mpu6050_read_normalize_gyro);    
  mrbc_define_method(0, class_mpu6050, "gyro_x", class_mpu6050_gyro_x);
  mrbc_define_method(0, class_mpu6050, "gyro_y", class_mpu6050_gyro_y);
  mrbc_define_method(0, class_mpu6050, "gyro_z", class_mpu6050_gyro_z);
}
#endif
