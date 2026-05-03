COMPILER=g++

.PHONY:clear 

program:main.o 
	${COMPILER}  main.o -o program

main.o:main.cpp
	${COMPILER} -c main.cpp -o main.o


clear:
	rm -f main.o program