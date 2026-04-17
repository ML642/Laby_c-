#pragma once 
#include <string>

class SongDuration {
    public :
        SongDuration(int minutes,int seconds){
            if(seconds>=60){
              minutes+=seconds/60;
              seconds=seconds%60;
            }
            this->minutes=minutes;
            this->seconds=seconds;
        };

        int get_total_seconds(){
           return this->seconds + this->minutes*60; 
        };

        std::string get_formatted(){
            std::string s = std::to_string(this->minutes) + "m "+ std::to_string(this->seconds)+'s'   ;
            return s;
        };


    private : 
     unsigned int minutes ;
     
     unsigned int seconds;
};