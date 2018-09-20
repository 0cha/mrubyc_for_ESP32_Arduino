#include "mrubyc_for_ESP32_Arduino.h"

#ifdef USE_WIFI
#include "WiFi.h"
#include "ext.h"

static void class_wifi_connect(mrb_vm *vm, mrb_value *v, int argc){
  unsigned char *ssid = GET_STRING_ARG(1);
  unsigned char *password = GET_STRING_ARG(2);
  
  WiFi.begin((char *)ssid, (char *)password);
  
}
static void class_wifi_wl_connected(mrb_vm *vm, mrb_value *v, int argc){
  if(WiFi.status() != WL_CONNECTED){
     SET_FALSE_RETURN();
   } else {
     SET_TRUE_RETURN();
   }
}
static void class_wifi_disconnect(mrb_vm *vm, mrb_value *v, int argc){
  WiFi.disconnect();
}
static void class_wifi_local_ip(mrb_vm *vm, mrb_value *v, int argc){
  mrb_value value = mrbc_string_new_cstr(vm, WiFi.localIP().toString().c_str());
  SET_RETURN(value);
}
static void class_wifi_scan_networks(mrb_vm *vm, mrb_value *v, int argc){
  int n = WiFi.scanNetworks();
  if (n == 0) {
    SET_FALSE_RETURN();
  } else {
    mrb_value ssids = mrbc_array_new(vm, n);
    for(int i = 0; i < n; i++){
      mrb_value ssid = mrbc_string_new_cstr(vm, WiFi.SSID(i).c_str());
      mrbc_dup(&ssid);
      mrbc_array_set(&ssids, i, &ssid);
    }
    SET_RETURN(ssids);
  }
}
void define_wifi_class(void){
  mrb_class *class_wifi;
  class_wifi = mrbc_define_class(0, "WiFi", mrbc_class_object);
  mrbc_define_method(0, class_wifi, "connect", class_wifi_connect);
  mrbc_define_method(0, class_wifi, "local_ip", class_wifi_local_ip);
  mrbc_define_method(0, class_wifi, "disocnnect", class_wifi_disconnect);
  mrbc_define_method(0, class_wifi, "scan_networks", class_wifi_scan_networks);
  mrbc_define_method(0, class_wifi, "connected?", class_wifi_wl_connected);
}
#endif
