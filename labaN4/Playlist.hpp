#pragma once 
#include "Song.hpp"
class Playlist{
    private:
        void resize(unsigned int new_capacity);
        Song* songs;
        unsigned int capacity;
        unsigned int size;
    public:
        Playlist();
        Playlist(int capacity);
        
        ~Playlist() ;
  
        Playlist(const Playlist& other) ;
        Playlist(Playlist&& other) ;
   
        Playlist& operator=(const Playlist& other) ;
        Playlist& operator=(Playlist&& other) ;




        void add_song(const Song& song);
        int get_size() const;
        void print();
};

