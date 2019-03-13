WiFi.connect('SSID','PASSWORD')
while !WiFi.connected?
  sleep(1)
end
gmOffset_sec = 9 * 3600
daylightOffset_sec = 0
if(WiFi.connected?)
  puts "WiFi connected"
  puts "IP: #{WiFi.local_ip}"
  now_date = Arduino.new
  now_date.configTime(gmOffset_sec, daylightOffset_sec, 'ntp.jst.mfeed.ad.jp')
  while true
    puts now_date.getLocalTime()
    puts now_date.time
    puts "#{now_date.year}/#{now_date.month}/#{now_date.day}(#{now_date.wday}) #{now_date.hour}:#{now_date.min}:#{now_date.sec}"
    sleep(1)    
  end
end
