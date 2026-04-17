#pragma once 
#include "SongDuration.hpp"


class Song {
    private:
        std::string tittle;
        std::string artist;
        SongDuration duration;
    public:

        Song();
        Song(std::string tittle_nazwa , int minutes, std::string artist);
        Song(std::string tittle_nazwa , SongDuration minutes, std::string artist);
    
        
}
