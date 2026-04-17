CXX=g++
CXXFLAGS=-std=c++17 -Wall -fsanitize=address,leak -g
LDFLAGS=-fsanitize=address,leak

.PHONY: all clean

all: l3

l3: main.o 
	${CXX} main.o  -o l3

main.o:main.cpp
	${CXX} -c main.cpp -o main.o


clean:
	rm -f *.o l3	