COMPILER=g++

.PHONY: all
all: main_program
mini_vector.o:mini_vector.cpp
	${COMPILER} -c mini_vector.cpp -o mini_vector.o

main_program: main_program.o mini_vector.o
	${COMPILER} -g -fsanitize=address main_program.o mini_vector.o -o main_program

main_program.o: main.cpp
	${COMPILER} -c main.cpp -o main_program.o

.PHONY: clean
clean:
	rm -f main_program.o main_program mini_vector.o