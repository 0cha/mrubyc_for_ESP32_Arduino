#include "mrubyc_for_ESP32_Arduino.h"

#ifdef USE_MSGPACK
#include "msgpck.h"
#include "ext.h"
static void class_msgpack_map_next(mrb_vm *vm, mrb_value *v, int argc){
}
static void class_msgpack_what_next(mrb_vm *vm, mrb_value *v, int argc){
}
static void class_msgpack_nil_next(mrb_vm *vm, mrb_value *v, int argc){
}
void define_msgpack_class(void){
  mrb_class *class_msgpack;
  class_msgpack = mrbc_define_class(0, "MsgPack", mrbc_class_object);
}
#endif
