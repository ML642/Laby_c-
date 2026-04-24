CXX=g++
CXXFLAGS=-std=c++17 -Wall -fsanitize=address,leak -g
LDFLAGS=-fsanitize=address,leak

.PHONY: all clean

all: l3

l3:main.o Subtask.o Task.o
	${CXX} main.o Subtask.o Task.o -o l3 

main.o: main.cpp
	${CXX} -c main.cpp -o main.o

Task.o:Task.cpp 
	${CXX} -c Task.cpp -o Task.o

Subtask.o:Subtask.cpp
	${CXX} -c Subtask.cpp -o Subtask.o


clean:
	rm -f *.o l3 