# encoding: utf-8
class HCSR04
  attr_accessor :duration, :distance
  EchoPin = 12
  TrigPin = 13
  def initialize
    @duration = 0
    @distance = 0
    Arduino.pin_mode(EchoPin, :INPUT)
    Arduino.pin_mode(TrigPin, :OUTPUT)
  end

  def distance(temperature = 25)
    Arduino.digital_write(TrigPin, :LOW)
    Arduino.delayMicroseconds(2)
    Arduino.digital_write(TrigPin, :HIGH)
    Arduino.delayMicroseconds(10)
    Arduino.digital_write(TrigPin, :LOW)
    @duration = Arduino.pulseIn(EchoPin, :HIGH)

    if(@duration > 0)
      @duration = @duration / 2
      @distance = @duration * ((331.5 + temperature) * 0.61) * 100 / 1000000
      return @distance # cm
    end
  end
end

hcsr04 = HCSR04.new
hcsr04.initialize

while true
  puts "#{hcsr04.distance} cm"
  sleep_ms(500)
end
