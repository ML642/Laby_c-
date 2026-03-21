COMPILER=g++

.PHONY: all clean 

all: main_program test1

main_program.o:main_program.cpp
	${COMPILER} -c main_program.cpp  -o main_program.o

hello.o:hello.cpp
	${COMPILER} -c -fPIC hello.cpp -o hello.o
libhello.so:hello.o
	${COMPILER} -shared hello.o -o libhello.so

main_program: main_program.o libhello.so
	${COMPILER}	main_program.o -L. -lhello -o main_program


strings.o:strings.cpp
	${COMPILER} -c strings.cpp -o strings.o

vectors.o: vectors.cpp	
	${COMPILER} -c vectors.cpp -o vectors.o


liboperations.a: vectors.o strings.o
	ar rcs liboperations.a vectors.o strings.o

test.o:test1.cpp
	${COMPILER} -c test1.cpp -o test.o

test:test.o liboperations.a
	${COMPILER} test.o -L. -loperations -o test

clean:
	rm -f main_program hello.o main_program.o libhello.so	
	