/*
  ext.h

  Header file of extension methods
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/

#ifndef __EXT_H_
#define __EXT_H_

#include "libmrubyc_config.h"
#include "value.h"

#define RECV_BUFF_SIZE 1024

bool mrbc_trans_cppbool_value(mrbc_vtype tt);
void define_arduino_class(void);
void define_serial_class(void);
#ifdef USE_ARDUINO_TIME
void define_arduino_time(void);
#endif
#ifdef USE_WIFI
void define_wifi_class(void);
#endif
#ifdef USE_HTTP_CLIENT
void define_http_client_class(void);
#endif
#ifdef USE_BMP085
void define_bmp085_class(void);
#endif
#ifdef USE_BME280
void define_bme280_class(void);
#endif
#ifdef USE_RPR0521RS
void define_rpr0521rs_class(void);
#endif
#ifdef USE_MSGPACK
void define_msgpack_class(void);
#endif
#ifdef ARDUINO_M5Stack_Core_ESP32
void define_m5stack_class(void);
#ifdef USE_M5AVATAR
void define_m5avatar_class(void);
#endif
#endif

#endif
