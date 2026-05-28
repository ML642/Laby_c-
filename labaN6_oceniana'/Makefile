CXX=g++
CXXFLAGS=-std=c++17 -Wall -fsanitize=address,leak -g
LDFLAGS=-fsanitize=address,leak

.PHONY: all clean

all: l6

l6: main.o
	${CXX} main.o -o l6 ${CXXFLAGS}

main.o:main.cpp
	${CXX} -c main.cpp -o  main.o 

clean:
	rm -f *.o l6