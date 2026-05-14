CXX=g++
CXXFLAGS=-std=c++17 -Wall -fsanitize=address,leak -g
LDFLAGS=-fsanitize=address,leak

.PHONY: all clean

all: l3

l3 : main.o Song.o Playlist.o
	${CXX}  main.o Song.o Playlist.o -o l3  

main.o:main.cpp
	${CXX} -c main.cpp -o main.o
Song.o:Song.cpp
	${CXX} -c Song.cpp -o Song.o

Playlist.o : Playlist.cpp
	${CXX} -c Playlist.cpp -o Playlist.o

clean:
	rm -f *.o l3