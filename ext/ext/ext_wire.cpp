#include "mrubyc_for_ESP32_Arduino.h"

#ifdef USE_WIRE
#include "Wire.h"
#include "ext.h"

static void class_wire_begin(mrb_vm *vm, mrb_value *v, int argc){
  Wire.begin();
}
static void class_wire_begin_transmission(mrb_vm *vm, mrb_value *v, int argc){
  int address = GET_INT_ARG(1);
  Wire.beginTransmission(address);
}
static void class_wire_write(mrb_vm *vm, mrb_value *v, int argc){
  int byte = GET_INT_ARG(1);
  Wire.write(byte);
}
static void class_wire_end_transmission(mrb_vm *vm, mrb_value *v, int argc){
  Wire.endTransmission();
}
static void class_wire_read(mrb_vm *vm, mrb_value *v, int argc){
  char byte =  Wire.read();
  SET_INT_RETURN(byte);
}
void define_wire_class(void){
  mrb_class *class_wire;
  class_wire = mrbc_define_class(0, "Wire", mrbc_class_object);
  mrbc_define_method(0, class_wire, "begin", class_wire_begin);
  mrbc_define_method(0, class_wire, "beginTransmission", class_wire_begin_transmission);
  mrbc_define_method(0, class_wire, "endTransmission", class_wire_end_transmission);
  mrbc_define_method(0, class_wire, "write", class_wire_write);
  mrbc_define_method(0, class_wire, "read", class_wire_read);
}
#endif
