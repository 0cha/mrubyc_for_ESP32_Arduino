#include "mrubyc_for_ESP32_Arduino.h"

#ifdef USE_BMP085
#include "Arduino.h"
#include "Wire.h"
#include <Adafruit_BMP085.h>
#include "ext.h"

Adafruit_BMP085 bmp;

static void class_bmp085_begin(mrb_vm *vm, mrb_value *v, int argc){
  byte c = 1;
  if(!bmp.begin()){
    console_print("Could not find a valid BMP085 sensor, check wiring!\n");
    SET_FALSE_RETURN();
  } else {
    SET_TRUE_RETURN();
  }
}
static void class_bmp085_readTemperature(mrb_vm *vm, mrb_value *v, int argc){
  float temp = bmp.readTemperature();
  SET_FLOAT_RETURN(temp);
}
static void class_bmp085_readPressure(mrb_vm *vm, mrb_value *v, int argc){
  float press = bmp.readPressure();
  SET_FLOAT_RETURN(press);
}
static void class_bmp085_readAltitude(mrb_vm *vm, mrb_value *v, int argc){
  float altitude = bmp.readAltitude();
  SET_FLOAT_RETURN(altitude);
}
static void class_bmp085_readSealevelPressure(mrb_vm *vm, mrb_value *v, int argc){
  float pascal;
  float sea_press;
  switch(GET_TT_ARG(1)){
  case MRB_TT_FIXNUM:
    pascal = (float)GET_INT_ARG(1);
    sea_press = bmp.readSealevelPressure(pascal);
    break;
  case MRB_TT_FLOAT:
    pascal = (float)GET_FLOAT_ARG(1);
    sea_press = bmp.readSealevelPressure(pascal);
    break;
  default:
    sea_press = bmp.readSealevelPressure();
    break;
  }
  SET_FLOAT_RETURN(sea_press);
}

void define_bmp085_class(void){
  mrb_class *class_bmp085;
  class_bmp085 = mrbc_define_class(0, "BMP085", mrbc_class_object);
  mrbc_define_method(0, class_bmp085, "begin", class_bmp085_begin);
  mrbc_define_method(0, class_bmp085, "readTemperature", class_bmp085_readTemperature);
  mrbc_define_method(0, class_bmp085, "readPressure", class_bmp085_readPressure);
  mrbc_define_method(0, class_bmp085, "readAltitude", class_bmp085_readAltitude);
  mrbc_define_method(0, class_bmp085, "readSealevelPressure", class_bmp085_readSealevelPressure);
}
#endif
