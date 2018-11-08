@echo off
cd /d %~dp0
set MRUBYC_SRC=mrubyc\src
echo %MRUBYC_SRC%\hal_posix
git submodule update -i
rd /s /q %MRUBYC_SRC%\hal_posix %MRUBYC_SRC%\hal_psoc5lp
move %MRUBYC_SRC%\hal_esp32 %MRUBYC_SRC%\hal

mklink /D %MRUBYC_SRC%\ext ..\..\ext\ext
mklink %MRUBYC_SRC%\libmrubyc_config.h ..\..\ext\libmrubyc_config.h
mklink %MRUBYC_SRC%\mrubyc_for_ESP32_Arduino.h ..\..\ext\mrubyc_for_ESP32_Arduino.h
mklink /D src %MRUBYC_SRC%

