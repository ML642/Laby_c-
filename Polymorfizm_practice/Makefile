COMPILER=g++

run: program
	./program
	rm -f main.o

program:main.o
	${COMPILER} main.o -o program


main.o:main.cpp
	${COMPILER} -c main.cpp -o main.o
