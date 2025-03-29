@echo off

REM Check for the COM port parameter
if "%~1" == "" (
    echo Usage: upload_latest_build.bat COMx
    exit /b
)


REM Run the esptool.py command with generic paths
%USERPROFILE%\.platformio\penv\Scripts\python.exe %USERPROFILE%\.platformio\packages\tool-esptoolpy\esptool.py --chip esp32s3 --port %1 --baud 921600 --before default_reset --after hard_reset write_flash -z 0x10000 .pio\build\T-Display-AMOLED\firmware.bin
