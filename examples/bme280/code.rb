# -*- coding: utf-8 -*-
bme280 = BME280.new
bme280.set_mode()
while true
  bme280.read_data()
  puts "Temperature: #{bme280.temperature}"
  puts "Pressure: #{bme280.pressure}"
  puts "Humidity: #{bme280.humidity}"
  sleep(1)
end
