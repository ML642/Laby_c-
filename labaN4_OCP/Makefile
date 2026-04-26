CXX=g++
CXXFLAGS=-std=c++17 -Wall -fsanitize=address,leak -g
LDFLAGS=-fsanitize=address,leak

.PHONY: all clean

all: l3

l3 : Subtask.o main.o Task.o
	${CXX} main.o Subtask.o Task.o -o l3

main.o:main.cpp
	${CXX} -c main.cpp -o  main.o


Subtask.o : Subtask.cpp
	${CXX} -c Subtask.cpp -o Subtask.o

Task.o:Task.cpp
	${CXX} -c Task.cpp -o Task.o 

clean:
	rm -f *.o l3