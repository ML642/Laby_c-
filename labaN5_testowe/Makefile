COMPILER=g++

.PHONY:clear 

program:main.o MovieCollection.o
	${COMPILER}  main.o  MovieCollection.o -o program

main.o:main.cpp
	${COMPILER} -c main.cpp -o main.o

MovieCollection.o:MovieCollection.cpp
	${COMPILER} -c MovieCollection.cpp -o MovieCollection.o

clear:
	rm -f main.o program