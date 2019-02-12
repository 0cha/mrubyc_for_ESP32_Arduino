/*
  ext.cpp

  Defining extension methods for ESP32
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/

#include "mrubyc_for_ESP32_Arduino.h"
#include "ext.h"

bool mrbc_trans_cppbool_value(mrbc_vtype tt)
{
	if(tt==MRBC_TT_TRUE){
		return true;
	}
	return false;
}

void mrbc_define_methods(void)
{
	define_arduino_class();
	define_serial_class();
#ifdef USE_ARDUINO_TIME
	define_arduino_time();
#endif
#ifdef USE_WIFI
	define_wifi_class();
#endif
#ifdef USE_HTTP_CLIENT
	define_http_client_class();
#endif
#ifdef USE_BMP085
	define_bmp085_class();
#endif
#ifdef USE_BME280
	define_bme280_class();
#endif
#ifdef USE_RPR0521RS
	define_rpr0521rs_class();
#endif
#ifdef USE_KXG03
	define_kxg03_class();
#endif 
	//define_esp32_class();
#ifdef ARDUINO_M5Stack_Core_ESP32
	define_m5stack_class();
#ifdef USE_M5AVATAR
	define_m5avatar_class();
#endif
#endif
}
