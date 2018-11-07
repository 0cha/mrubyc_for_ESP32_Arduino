WiFi.connect('aterm-64a087-g','2a6b14815f363')
while !WiFi.connected?
  sleep(1)
end
gmOffset_sec = 9 * 3600
daylightOffset_sec = 0
if(WiFi.connected?)
  puts "WiFi connected"
  puts "IP: #{WiFi.local_ip}"
  Arduino.configTime(gmOffset_sec, daylightOffset_sec, 'ntp.jst.mfeed.ad.jp')
  while true
    puts Arduino.time
    puts "#{Arduino.year}/#{Arduino.month}/#{Arduino.day}(#{Arduino.wday}) #{Arduino.hour}:#{Arduino.min}:#{Arduino.sec}"
    sleep(1)
  end
end
