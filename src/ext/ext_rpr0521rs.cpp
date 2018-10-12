#include "mrubyc_for_ESP32_Arduino.h"

#ifdef USE_RPR0521RS
#include "Arduino.h"
#include "Wire.h"
#include <RPR-0521RS.h>
#include "ext.h"

RPR0521RS rpr0521rs;

static void class_rpr0521rs_init(mrb_vm *vm, mrb_value *v, int argc){
  byte rc = rpr0521rs.init();
  if(rc != 0){
    SET_FALSE_RETURN();
  } else {
    SET_TRUE_RETURN();
  }
}
static void class_rpr0521rs_get_psalsval(mrb_vm *vm, mrb_value *v, int argc){
  unsigned short ps;
  float als;

  byte rc = rpr0521rs.get_psalsval(&ps, &als);

  mrb_value values = mrbc_array_new(vm, 2);
  mrb_value r_ps = mrb_fixnum_value(ps);
  mrb_value r_als = mrb_float_value(als);
  
  if(rc == 0){
    mrbc_dup(&r_ps);
    mrbc_array_set(&values, 0, &r_ps);
    mrbc_dup(&r_als);
    mrbc_array_set(&values, 1, &r_als);
    SET_RETURN(values);
  } else {
    SET_FALSE_RETURN();
  }
}
static void class_rpr0521rs_get_psval(mrb_vm *vm, mrb_value *v, int argc){}
static void class_rpr0521rs_get_alsval(mrb_vm *vm, mrb_value *v, int argc){}
static void class_rpr0521rs_check_near_far(mrb_vm *vm, mrb_value *v, int argc){}

void define_rpr0521rs_class(void){
  mrb_class *class_rpr0521rs;
  class_rpr0521rs = mrbc_define_class(0, "RPR0521RS", mrbc_class_object);
  mrbc_define_method(0, class_rpr0521rs, "init", class_rpr0521rs_init);
  mrbc_define_method(0, class_rpr0521rs, "get_psalsval", class_rpr0521rs_get_psalsval);
  mrbc_define_method(0, class_rpr0521rs, "get_psval", class_rpr0521rs_get_psval);
  mrbc_define_method(0, class_rpr0521rs, "check_near_far", class_rpr0521rs_check_near_far);
}
#endif
