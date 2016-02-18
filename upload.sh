#!/bin/bash
clear
make clean
make 
objcopy -O ihex -R .eeprom main_arduino.elf main_arduino.hex 
 sudo avrdude -c arduino -p m328p  -P /dev/ttyACM0 -U flash:w:main_arduino.hex
