CXX=g++
CXXFLAGS=-std=c++17 -Wall -fsanitize=address,leak -g
LDFLAGS=-fsanitize=address,leak

.PHONY: all clean

all: l3

l3: main.o song.o 
	${CXX} main.o song.o -o l3

song.o : song.cpp
	${CXX} -c song.cpp -o song.o

main.o:main.cpp
	${CXX} -c main.cpp -o main.o


clean:
	rm -f *.o l3	