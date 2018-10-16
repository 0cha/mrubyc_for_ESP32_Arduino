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

WiFi.connect("aterm-64a087-g","2a6b14815f363")

while !WiFi.connected?
  sleep(1)
end

http = HTTPClient.new()
if(WiFi.connected?)
  puts "connected!"
  #http.begin("host_address", 80, "/temperatures.json")
  #http.addHeader("Content-Type", "application/json")
end

while true
  puts "IP: #{WiFi.local_ip}"
  sleep(10)
end
