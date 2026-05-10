CXX=g++
CXXFLAGS=-std=c++17 -Wall -fsanitize=address,leak -g
LDFLAGS=-fsanitize=address,leak

.PHONY: all clean

all: l5



l5: main.o SensorCollection.o
	${CXX} main.o SensorCollection.o -o l5

SensorCollection.o:SensorCollection.cpp
	${CXX} -c SensorCollection.cpp -o SensorCollection.o

main.o:main.cpp
	${CXX} -c main.cpp -o main.o

clean:
	rm -f *.o l5