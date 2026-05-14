#pragma once 

#include <string>
#include <iostream>
#include "SongDuration.hpp"

class Song {

    private:


        std::string title;
        std::string artist;
        SongDuration duration;
    public:
        Song();
        Song(std::string tytul , SongDuration czas ,  std::string artist);
        Song(std::string tytul , int  czas ,  std::string artist);
        
        Song(std::string title , int czas);
        Song(std::string title , SongDuration czas);
        Song(std::string title , int minutes, int seconds , std::string artist);
        
        ~Song();
        
        void print();

        int get_duration();
        void set_duration(int duration);

        static  int get_total_songs();

        std::string get_artist();
        void set_artist(std::string artist);
        
        std::string get_title();
        void set_title(std::string title);

        static unsigned int count_songs;

};