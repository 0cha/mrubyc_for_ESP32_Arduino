# -*- coding: utf-8 -*-
class Array
  def each
    idx = 0
    while idx < length
      yield self[idx]
      idx += 1
    end
    self
  end
end

class TemperatureSensor
  def get(pin)
    b = 4275
    r0 = 100000
    raw_data = Arduino.analog_read(pin)
    r = 4095.0 / raw_data - 1.0
    r = r0 * r
    temp = 1.0 / (Math.log( r / r0) / b + 1 / 298.15) - 273.35
    return temp
  end
end

#Lcd display
Lcd.fill_screen(:WHITE)
Lcd.set_text_size(3)
Lcd.set_text_color(:BLACK)
temp_sensor = TemperatureSensor.new

WiFi.connect("AP","KEY")

while !WiFi.connected?
  sleep(1)
end

http = HTTPClient.new()
if(WiFi.connected?)
  puts "connected!"
  http.begin("host_address", 80, "/temperatures.json")
  http.addHeader("Content-Type", "application/json")
end

temp = 0.0

while true
   temp = temp_sensor.get(35)
   Lcd.set_cursor(0,0)
   Lcd.printf("temp: #{temp}")
   Lcd.set_cursor(0,21)
   Lcd.printf("IP: #{WiFi.local_ip}")
   http.post('{"temperature": {"temp": ' + temp.to_s +  '}}')
   sleep(300)
   Lcd.fill_screen(:WHITE)
   M5.update()
end
