#include <SD.h>
#include <mrubyc_for_ESP32_Arduino.h>

extern const uint8_t code[];

#define MEMSIZE (1024*50)
static uint8_t mempool[MEMSIZE];

void setup(){
  Serial.begin(115200);
  delay(1000);

  Serial.print("-------begin setup");
  mrbc_init(mempool, MEMSIZE);
  mrbc_define_methods();
  if(NULL == mrbc_create_task( code, 0 )){
    Serial.println("mrbc_create_task error");
    return;
  }
  Serial.println("--- run mruby script"); 
  mrbc_run();
}

void loop() {}
