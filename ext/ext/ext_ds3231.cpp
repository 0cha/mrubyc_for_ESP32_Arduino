#include "mrubyc_for_ESP32_Arduino.h"

#ifdef USE_DS3231
#include "Arduino.h"
#include "Wire.h"
#include <RTClib.h>
#include "ext.h"

RTC_DS3231 rtc;
mrbc_int year1, month1, day1, dow1, hour1, minutes1, second1;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

mrb_value get_datetime(mrb_vm *vm){
  DateTime now = rtc.now();
  char buf[20];
  sprintf(buf,
          "%04d%02d%02d%02d%02d%02d",
          now.year(),
          now.month(),
          now.day(),
          now.hour(),
          now.minute(),
          now.second()
          );
  year1 = now.year();
  month1 = now.month();
  day1 = now.day();
  dow1 = now.dayOfTheWeek();
  hour1 = now.hour();
  minutes1 = now.minute();
  second1 = now.second();
  return mrbc_string_new_cstr(vm, buf);
}

static void class_ds3231_init(mrb_vm *vm, mrb_value *v, int argc){
  rtc.begin();
}
static void class_ds3231_set_datetime(mrb_vm *vm, mrb_value *v, int argc){
  rtc.adjust(DateTime(GET_INT_ARG(1),GET_INT_ARG(2),GET_INT_ARG(3),GET_INT_ARG(4),GET_INT_ARG(5),GET_INT_ARG(6)));
  mrb_value time_s = get_datetime(vm);
  SET_RETURN(time_s);
}
static void class_ds3231_get_datetime(mrb_vm *vm, mrb_value *v, int argc){
  mrb_value time_s = get_datetime(vm);
  SET_RETURN(time_s);
}
static void class_ds3231_get_date(mrb_vm *vm, mrb_value *v, int argc){
  DateTime now = rtc.now();
  char buf[20];
  sprintf(buf,
          "%04d/%02d/%02d",
          now.year(),
          now.month(),
          now.day()
          );
  year1 = now.year();
  month1 = now.month();
  day1 = now.day();
  mrb_value time_s = mrbc_string_new_cstr(vm, buf);
  SET_RETURN(time_s);
}
static void class_ds3231_get_time(mrb_vm *vm, mrb_value *v, int argc){
  DateTime now = rtc.now();
  char buf[20];
  sprintf(buf,
          "%02d:%02d:%02d",
          now.hour(),
          now.minute(),
          now.second()
          );
  hour1 = now.hour();
  minutes1 = now.minute();
  second1 = now.second();
  mrb_value time_s = mrbc_string_new_cstr(vm, buf);
  SET_RETURN(time_s);
}

static void class_ds3231_year(mrb_vm *vm, mrb_value *v, int argc){
  SET_INT_RETURN(year1);
}
static void class_ds3231_month(mrb_vm *vm, mrb_value *v, int argc){
  SET_INT_RETURN(month1);
}
static void class_ds3231_day(mrb_vm *vm, mrb_value *v, int argc){
  SET_INT_RETURN(day1);
}
static void class_ds3231_dow(mrb_vm *vm, mrb_value *v, int argc){
  SET_INT_RETURN(dow1);
}
static void class_ds3231_hour(mrb_vm *vm, mrb_value *v, int argc){
  SET_INT_RETURN(hour1);
}
static void class_ds3231_minute(mrb_vm *vm, mrb_value *v, int argc){
  SET_INT_RETURN(minutes1);
}
static void class_ds3231_second(mrb_vm *vm, mrb_value *v, int argc){
  SET_INT_RETURN(second1);
}

void define_ds3231_class(void){
  mrb_class *class_ds3231;
  class_ds3231 = mrbc_define_class(0, "DS3231", mrbc_class_object);
  mrbc_define_method(0, class_ds3231, "init", class_ds3231_init);
  mrbc_define_method(0, class_ds3231, "setDateTime", class_ds3231_set_datetime);
  mrbc_define_method(0, class_ds3231, "getDateTime", class_ds3231_get_datetime);
  mrbc_define_method(0, class_ds3231, "get_date", class_ds3231_get_date);
  mrbc_define_method(0, class_ds3231, "get_time", class_ds3231_get_time);
  mrbc_define_method(0, class_ds3231, "year", class_ds3231_year);
  mrbc_define_method(0, class_ds3231, "month", class_ds3231_month);
  mrbc_define_method(0, class_ds3231, "day", class_ds3231_day);
  mrbc_define_method(0, class_ds3231, "dow", class_ds3231_dow);
  mrbc_define_method(0, class_ds3231, "hour", class_ds3231_hour);
  mrbc_define_method(0, class_ds3231, "min", class_ds3231_minute);
  mrbc_define_method(0, class_ds3231, "sec", class_ds3231_second);

}
#endif
