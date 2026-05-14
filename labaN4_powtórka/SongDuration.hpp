#pragma once 
#include <string>

class SongDuration{
    private:
        unsigned int minutes;
        unsigned int seconds;
    public:
        SongDuration():minutes(0),seconds(0){};
        SongDuration(int minutes, int seconds):minutes(minutes+seconds/60), seconds(seconds%60){};

        int get_total_seconds(){
            return this->seconds+this->minutes*60;
        }
        std::string get_formatted(){
            return std::to_string(this->minutes) + "m " + std::to_string(this->seconds)+'s';
        }

        

    };