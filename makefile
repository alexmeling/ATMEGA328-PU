
VPATH = sources headers 
#vpath %.cpp ~/programacion/arduino/arduino/sources/*



objects = main.o ports.o

main_arduino: $(objects)
	avr-g++  -mmcu=atmega328p -o main_arduino.elf $(objects)
		
main.o: main.cpp ports.h
	avr-g++   -mmcu=atmega328p  -c  main.cpp
ports.o: ports.cpp ports.h
	avr-g++  -mmcu=atmega328p  -c sources/ports.cpp 
clean: 
	rm main_arduino.hex main_arduino.elf $(objects)
