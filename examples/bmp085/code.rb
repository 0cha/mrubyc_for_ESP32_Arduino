# -*- coding: utf-8 -*-
bmp085 = BMP085.new
bmp085.begin()
while true
  puts bmp085.readTemperature
  puts bmp085.readPressure
  puts bmp085.readAltitude
  puts bmp085.readSealevelPressure
  puts bmp085.readSealevelPressure(10500)
  puts bmp085.readSealevelPressure(10500.0)
  sleep(10)
end
