#include "mrubyc_for_ESP32_Arduino.h"
#ifdef USE_ARDUINO_TIME
#include "Arduino.h"
#include "time.h"

time_t t;
struct tm *tm;

mrbc_int year, month, day, wday, hour, minute, sec;

static void class_arduino_config_time(mrb_vm *vm, mrb_value *v, int argc ){
	long timezone;
	int daylightOffset_sec;
	const char* server1;
	const char* server2;
	const char* server3;
	if(GET_TT_ARG(1) == MRBC_TT_FIXNUM){
		timezone = (long)GET_INT_ARG(1);
	} else {
		SET_FALSE_RETURN();
		return;
	}
	if(GET_TT_ARG(2) == MRBC_TT_FIXNUM){
	daylightOffset_sec = GET_INT_ARG(2);
	} else {
		SET_FALSE_RETURN();
		return;
	}
	if(GET_TT_ARG(3) == MRBC_TT_STRING){
		server1 = (const char*)GET_STRING_ARG(3);
	} else {
		SET_FALSE_RETURN();
		return;
	}
	if(GET_TT_ARG(4) == MRBC_TT_STRING){
		server2 = (const char*)GET_STRING_ARG(4);
	} else {
		server2 = NULL;
	}
	if(GET_TT_ARG(5) == MRBC_TT_STRING){
		server3 = (const char*)GET_STRING_ARG(5);
	} else {
		server3 = NULL;
	}
	configTime(timezone, daylightOffset_sec, server1, server2, server3);
	SET_TRUE_RETURN();
}
static void class_arduino_time(mrb_vm *vm, mrb_value *v, int argc ){
	char buf[40];
	t = time(NULL);
	tm = localtime(&t);
	year     = tm->tm_year + 1900;
	month    = tm->tm_mon + 1;
	day      = tm->tm_mday;
	wday     = tm->tm_wday;
	hour     = tm->tm_hour;
	minute   = tm->tm_min;
	sec      = tm->tm_sec;
	sprintf(buf,
					"%04d/%02d/%02d(%d) %02d:%02d:%02d",
					tm->tm_year + 1900,
					tm->tm_mon + 1,
					tm->tm_mday,
          tm->tm_wday,
					tm->tm_hour,
					tm->tm_min,
					tm->tm_sec
	
					);
	mrb_value time_s = mrbc_string_new_cstr(vm, buf);
	SET_RETURN(time_s);
}
static void class_arduino_year(mrb_vm *vm, mrb_value *v, int argc ){
	SET_INT_RETURN(year);
}
static void class_arduino_month(mrb_vm *vm, mrb_value *v, int argc ){
	SET_INT_RETURN(month);
}
static void class_arduino_day(mrb_vm *vm, mrb_value *v, int argc ){
	SET_INT_RETURN(day);
}
static void class_arduino_wday(mrb_vm *vm, mrb_value *v, int argc ){
	SET_INT_RETURN(wday);
}
static void class_arduino_hour(mrb_vm *vm, mrb_value *v, int argc ){
	SET_INT_RETURN(hour);
}
static void class_arduino_min(mrb_vm *vm, mrb_value *v, int argc ){
	SET_INT_RETURN(minute);
}
static void class_arduino_sec(mrb_vm *vm, mrb_value *v, int argc ){
	SET_INT_RETURN(sec);
}

void define_arduino_time(void){
	mrb_class *class_arduino;
	class_arduino = mrbc_define_class(0, "Arduino", mrbc_class_object);
	mrbc_define_method(0, class_arduino, "configTime", class_arduino_config_time);
	mrbc_define_method(0, class_arduino, "time", class_arduino_time);
	mrbc_define_method(0, class_arduino, "year", class_arduino_year);
	mrbc_define_method(0, class_arduino, "month", class_arduino_month);
	mrbc_define_method(0, class_arduino, "day", class_arduino_day);
	mrbc_define_method(0, class_arduino, "wday", class_arduino_wday);
	mrbc_define_method(0, class_arduino, "hour", class_arduino_hour);
	mrbc_define_method(0, class_arduino, "min", class_arduino_min);
	mrbc_define_method(0, class_arduino, "sec", class_arduino_sec);
}
#endif
