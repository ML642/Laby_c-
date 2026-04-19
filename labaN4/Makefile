CXX=g++
CXXFLAGS=-std=c++17 -Wall -fsanitize=address,leak -g
LDFLAGS=-fsanitize=address,leak

.PHONY: all clean

all: l3

l3: main.o song.o Playlist.o
	${CXX} main.o song.o  Playlist.o  -o l3

song.o : song.cpp
	${CXX} -c song.cpp -o song.o

main.o:main.cpp
	${CXX} -c main.cpp -o main.o

Playlist.o:Playlist.cpp
	${CXX} -c Playlist.cpp -o Playlist.o


clean:
	rm -f *.o l3	