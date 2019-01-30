#include "mrubyc_for_ESP32_Arduino.h"

#ifdef USE_HTTP_CLIENT
#include "HTTPClient.h"
#include "ext.h"

HTTPClient http;

static void class_http_client_begin(mrb_vm *vm, mrb_value *v, int argc){
  const char *host = reinterpret_cast<const char *>GET_STRING_ARG(1);
  const char *uri = reinterpret_cast<const char *>(GET_STRING_ARG(3));
  int port = GET_INT_ARG(2);

  if(GET_TT_ARG(4) == MRBC_TT_STRING){
    const char *root_ca = reinterpret_cast<const char *>(GET_STRING_ARG(4));
    http.begin(host, port, uri, root_ca);
  } else {
    http.begin(host, port, uri);
  }
  SET_TRUE_RETURN();
}

static void class_http_client_add_header(mrb_vm *vm, mrb_value *v, int argc){
  const char *header = reinterpret_cast<const char*>(GET_STRING_ARG(1));
  const char *mime = reinterpret_cast<const char*>(GET_STRING_ARG(2));
  http.addHeader(header, mime);
  SET_TRUE_RETURN();
}
static void class_http_client_post(mrb_vm *vm, mrb_value *v, int argc){
  const char *data = reinterpret_cast<const char *>(GET_STRING_ARG(1));
  http.POST((uint8_t *)data, strlen(data));
}
static void class_http_client_end(mrb_vm *vm, mrb_value *v, int argc){
  http.end();
}
void define_http_client_class(void){
  mrb_class *class_http_client;
  class_http_client = mrbc_define_class(0,"HTTPClient", mrbc_class_object);
  mrbc_define_method(0, class_http_client, "begin", class_http_client_begin);
  mrbc_define_method(0, class_http_client, "addHeader", class_http_client_add_header);
  mrbc_define_method(0, class_http_client, "post", class_http_client_post);
  mrbc_define_method(0, class_http_client, "end", class_http_client_end);
}
#endif
