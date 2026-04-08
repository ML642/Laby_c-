CXX=g++
CXXFLAGS=-Wall -fsanitize=address,leak
LDFLAGS=-fsanitize=address,leak

.PHONY: all clean

all: l2

holey_string.o:holey_string.cpp
	${CXX} -c holey_string.cpp -o holey_string.o

vector3.o:vector3.cpp
	${CXX} -c vector3.cpp -o vector3.o ${CXXFLAGS} ${LDFLAGS}

main.o:main.cpp
	${CXX} -c main.cpp -o main.o ${CXXFLAGS} ${LDFLAGS}


l2: main.o vector3.o holey_string.o
	${CXX} main.o vector3.o  holey_string.o -o l2 ${CXXFLAGS} ${LDFLAGS}

clean:
	rm -f l2 main.o holey_string.o vector3.o