CXX=g++
CXXFLAGS=-Wall -fsanitize=address,leak
LDFLAGS=-fsanitize=address,leak

.PHONY: all clean

all: l2

main.o: main.cpp
	${CXX} -c main.cpp -o main.o
vector3.o:vector3.cpp
	${CXX} -c vector3.cpp -o vector3.o



l2: vector3.o main.o 
	${CXX} vector3.o main.o -o l2  

clean:
	rm -f l2 vector3.o main.o
