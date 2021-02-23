CC=g++

CFLAGS=-std=c++11

all: solar-position-calculator

solar-position-calculator: main.o SolarPositionCalculation.o Date.o AzimuthElevation.o TimeLocation.o
				g++ main.o SolarPositionCalculation.o Date.o AzimuthElevation.o TimeLocation.o -o solar-position-calculator

main.o: main.cpp SolarPositionCalculation.cpp Date.cpp AzimuthElevation.cpp TimeLocation.cpp

clean:
	rm -rf *.o

run: solar-position-calculator
	./solar-position-calculator
