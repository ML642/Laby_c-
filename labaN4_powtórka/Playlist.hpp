#pragma once 

#include <iostream>
#include <string>
#include "Song.hpp"

class Playlist {    
    private:
        Song* songs;
        unsigned int capacity=10;
        unsigned int size;

        void resize(unsigned int new_capacity);
    public:
        Playlist(int capacity);
        Playlist();

        Playlist(const Playlist& other);
        
        Playlist(Playlist&& other);
        Playlist& operator=(Playlist& other);

        Playlist& operator=(const Playlist& other);
        Playlist& operator=(Playlist&& other);

        void add_song(const Song& song);
        int get_size();
        void print();
        
};