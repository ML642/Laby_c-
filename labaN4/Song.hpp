#pragma once 
#include "SongDuration.hpp"
#include <iostream>

class Song {
    
    private:
        static int count_songs;
        std::string title;
        std::string artist;
        SongDuration duration;
    public:

        Song();
        Song(std::string title_nazwa , int minutes, std::string artist);
        Song(std::string title_nazwa , SongDuration minutes, std::string artist);
        Song(std::string title, int duration);
        Song(std::string title, SongDuration duration);
        Song(std::string title, int seconds , int minutes ,  std::string artist );



        void print();

        std::string get_title();

        std::string get_artist();

        void set_title(std::string tittle);

        void set_artist(std::string artist);


        int get_duration();

        void set_duration(int seconds);

        static int  get_total_songs();
        
        
};
