LED_PIN = 27
Arduino.pin_mode(LED_PIN, :OUTPUT)

while true
  puts "Hello mruby/c World"
  Arduino.digital_write(LED_PIN, :HIGH)
  sleep_ms 250
  Arduino.digital_write(LED_PIN, :LOW)
  sleep_ms 250
end
