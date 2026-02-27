COMPILER=g++

.PHONY:all

all:program_1 test

hello.o:hello.cpp
	${COMPILER} -c -fPIC hello.cpp -o hello.o

libhello.so:hello.o
	${COMPILER}  -shared hello.o -o libhello.so

main_program.o:main_program.cpp
	${COMPILER} -c main_program.cpp -o main_program.o
program_1: libhello.so main_program.o
	${COMPILER} main_program.o -L. -lhello -o program_1


strings.o:strings.cpp
	${COMPILER} -c strings.cpp -o strings.o
vectors.o:vectors.cpp
	${COMPILER} -c vectors.cpp -o vectors.o

liboperations.a:vectors.o strings.o
	ar rcs  liboperations.a vectors.o strings.o

test.o:test.cpp
	${COMPILER} -c test.cpp -o test.o

test:test.o liboperations.a
	${COMPILER} test.o -L. -loperations -o test

.PHONY:clean

clean:
	rm -rf hello.o main_program.o strings.o vectors.o test.o
	rm -rf libhello.so liboperations.a
	rm -rf program_1 test
	