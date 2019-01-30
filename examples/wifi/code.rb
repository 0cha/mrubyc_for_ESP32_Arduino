WiFi.connect('SSID', 'PASSWORD')

while !WiFi.connected?
  sleep(1)
end

if(WiFi.connected?)
  puts "MAC: #{WiFi.macAddress}"
  puts "IP: #{WiFi.local_ip}"
end
