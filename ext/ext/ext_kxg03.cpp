#include "mrubyc_for_ESP32_Arduino.h"
#ifdef USE_KXG03
#include "Arduino.h"
#include <KXG03.h>
#include "ext.h"

KXG03 kxg03;
float val[6];
byte rc;
float gx,gy,gz,ax,ay,az;

static void class_kxg03_init(mrb_vm *vm, mrb_value *v, int argc){
  rc = kxg03.init(KXG03_DEVICE_ADDRESS_4E);
}
static void class_kxg03_get_val(mrb_vm *vm, mrb_value *v, int argc){
  rc = kxg03.get_val(val);
  if(rc == 0){
    gx = val[0]; // Gyro X
    gy = val[1]; // Gyro Y
    gz = val[2]; // Gyro Z
    ax = val[3]; // Accel X
    ay = val[4]; // Accel Y
    az = val[5]; // Accel Z
    SET_TRUE_RETURN();
  } else {
    SET_FALSE_RETURN();
  }
}
static void class_kxg03_gyro_x(mrb_vm *vm, mrb_value *v, int argc){
  SET_FLOAT_RETURN(gx);
}
static void class_kxg03_gyro_y(mrb_vm *vm, mrb_value *v, int argc){
  SET_FLOAT_RETURN(gy);
}
static void class_kxg03_gyro_z(mrb_vm *vm, mrb_value *v, int argc){
  SET_FLOAT_RETURN(gz);
}
static void class_kxg03_accel_x(mrb_vm *vm, mrb_value *v, int argc){
  SET_FLOAT_RETURN(ax);
}
static void class_kxg03_accel_y(mrb_vm *vm, mrb_value *v, int argc){
  SET_FLOAT_RETURN(ay);
}
static void class_kxg03_accel_z(mrb_vm *vm, mrb_value *v, int argc){
  SET_FLOAT_RETURN(az);
}

void define_kxg03_class(void){
  mrb_class *class_kxg03;
  class_kxg03 = mrbc_define_class(0, "KXG03", mrbc_class_object);
  mrbc_define_method(0, class_kxg03, "init", class_kxg03_init);
  mrbc_define_method(0, class_kxg03, "get_val", class_kxg03_get_val);
  mrbc_define_method(0, class_kxg03, "gyro_x", class_kxg03_gyro_x);
  mrbc_define_method(0, class_kxg03, "gyro_y", class_kxg03_gyro_y);
  mrbc_define_method(0, class_kxg03, "gyro_z", class_kxg03_gyro_z);
  mrbc_define_method(0, class_kxg03, "accel_x", class_kxg03_accel_x);
  mrbc_define_method(0, class_kxg03, "accel_y", class_kxg03_accel_y);
  mrbc_define_method(0, class_kxg03, "accel_z", class_kxg03_accel_z);  
}
#endif
