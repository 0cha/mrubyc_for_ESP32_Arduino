@echo off
cd /d %~dp0
set MRUBYC_SRC=%CD%\mrubyc\src
git submodule update -i
rd /s /q %MRUBYC_SRC%\hal_posix %MRUBYC_SRC%\hal_psoc5lp
move %MRUBYC_SRC%\hal_esp32 %MRUBYC_SRC%\hal

mklink /D %MRUBYC_SRC%\ext %CD%\ext\ext
mklink %MRUBYC_SRC%\libmrubyc_config.h %CD%\ext\libmrubyc_config.h
mklink %MRUBYC_SRC%\mrubyc_for_ESP32_Arduino.h %CD%\ext\mrubyc_for_ESP32_Arduino.h
mklink /D %CD%\src %MRUBYC_SRC%


