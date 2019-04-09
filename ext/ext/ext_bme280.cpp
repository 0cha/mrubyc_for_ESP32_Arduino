#include "mrubyc_for_ESP32_Arduino.h"

#ifdef USE_BME280
#include "Arduino.h"
#include "ext.h"
#include <SSCI_BME280.h>
SSCI_BME280 bme280;
uint8_t addr = 0x76;
double temperature, pressure, humidity;
static void class_bme280_set_mode(mrb_vm *vm, mrb_value *v, int argc){
  uint8_t osrs_t = 1;
  uint8_t osrs_p = 1;
  uint8_t osrs_h = 1;
  uint8_t mode = 3;
  uint8_t t_sb = 5;
  uint8_t filter = 0;
  uint8_t spi3w_en =  0;
  
  if(GET_TT_ARG(1) == MRBC_TT_FIXNUM){
    addr = GET_INT_ARG(1);
  }
  if(GET_TT_ARG(2) == MRBC_TT_FIXNUM){
    osrs_t = GET_INT_ARG(2);
  }
  if(GET_TT_ARG(3) == MRBC_TT_FIXNUM){
    osrs_p = GET_INT_ARG(3);
  }
  if(GET_TT_ARG(4) == MRBC_TT_FIXNUM){
    osrs_h = GET_INT_ARG(4);
  }
  if(GET_TT_ARG(5) == MRBC_TT_FIXNUM){
    mode = GET_INT_ARG(5);
  }
  if(GET_TT_ARG(6) == MRBC_TT_FIXNUM){
    mode = GET_INT_ARG(6);
  }
  if(GET_TT_ARG(7) == MRBC_TT_FIXNUM){
    t_sb = GET_INT_ARG(7);
  }
  if(GET_TT_ARG(7) == MRBC_TT_FIXNUM){
    filter = GET_INT_ARG(8);
  }
  if(GET_TT_ARG(9) == MRBC_TT_FIXNUM){
    spi3w_en = GET_INT_ARG(9);
  }
  bme280.setMode(addr, osrs_t, osrs_p, osrs_h, mode, t_sb, filter, spi3w_en);
  bme280.readTrim();
  SET_TRUE_RETURN();
}
static void class_bme280_read_data(mrb_vm *vm, mrb_value *v, int argc){
  bme280.readData(&temperature, &pressure, &humidity);
  SET_TRUE_RETURN();
}
static void class_bme280_temperature(mrb_vm *vm, mrb_value *v, int argc){
  SET_FLOAT_RETURN((float)temperature);
}
static void class_bme280_pressure(mrb_vm *vm, mrb_value *v, int argc){
  SET_FLOAT_RETURN((float)pressure);
}
static void class_bme280_humidity(mrb_vm *vm, mrb_value *v, int argc){
  SET_FLOAT_RETURN((float)humidity);
}
void define_bme280_class(void){
  mrb_class *class_bme280;
  class_bme280 = mrbc_define_class(0, "BME280", mrbc_class_object);
  mrbc_define_method(0, class_bme280, "set_mode", class_bme280_set_mode);
  mrbc_define_method(0, class_bme280, "read_data", class_bme280_read_data);
  mrbc_define_method(0, class_bme280, "temperature", class_bme280_temperature);
  mrbc_define_method(0, class_bme280, "pressure", class_bme280_pressure);
  mrbc_define_method(0, class_bme280, "humidity", class_bme280_humidity); 
}
#endif
