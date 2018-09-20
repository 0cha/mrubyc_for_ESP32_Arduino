/*
  ext.cpp

  Defining extension methods for ESP32
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/

#include "mrubyc_for_ESP32_Arduino.h"
#include "ext.h"

bool mrbc_trans_cppbool_value(mrb_vtype tt)
{
	if(tt==MRB_TT_TRUE){
		return true;
	}
	return false;
}

void mrbc_define_methods(void)
{
	define_arduino_class();
	define_serial_class();
#ifdef USE_WIFI
	define_wifi_class();
#endif
#ifdef USE_HTTP_CLIENT
	define_http_client_class();
#endif
#ifdef USE_JSON
	define_json_class();
#endif
	//define_esp32_class();
#ifdef ARDUINO_M5Stack_Core_ESP32
	define_m5stack_class();
#ifdef USE_M5AVATAR
	define_m5avatar_class();
#endif
#endif
}

