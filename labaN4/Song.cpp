#include "Song.hpp"

int Song::count_songs = 0;

Song::Song(): title("unknown") , artist("unknown") ,  duration(0,0){
    Song::count_songs+=1;
};

Song::Song( std::string title  , SongDuration duration , std::string artist): title("unknown") , artist("unknown") , duration(0,0){
    Song::count_songs+=1;
    
    this->title = title ;
    this->artist = artist ; 
    this->duration = duration;
};
Song::Song( std::string title  ,int duration ): title("unknown") , artist("unknown") , duration(duration/60 ,duration%60){
      Song::count_songs+=1;
};

Song::Song(std::string title, int seconds , int minutes ,  std::string artist ):artist(artist), title(title) , duration(minutes,seconds) {
      Song::count_songs+=1;    
};


Song::Song( std::string title  ,SongDuration duration ): title("unknown") , artist("unknown") , duration(0,0){
      Song::count_songs+=1;
    this->title = title ; 
    this->duration = duration;
};

Song::Song(std::string title , int duration , std::string artist) : title("unknown") , artist("unknown"),duration(0,0) {
    Song::count_songs+=1;
    SongDuration s = {1,1};
    this->title = title ;
    this->artist = artist ; 

    this->duration = s;
};

std::string Song::get_artist(){
    return this->artist;
};

std::string Song::get_title(){
    return this->title;
};

void  Song::set_title(std::string title){
    this->title = title ;
};

void  Song::set_artist(std::string artist){
    this->artist = artist ;
};

int Song::get_duration(){
    return this->duration.get_total_seconds();
};

void Song::set_duration(int duration){
    int minutes = duration/60;
    int seconds = duration%60;
    
    this->duration = SongDuration(minutes,seconds);
}


int Song::get_total_songs(){
    return count_songs;
};

void Song::print(){
    std::cout<<this->title<<','<<' '<< "Artist"<<':'<< ' ' << this->artist <<' '<<'[' <<  this->duration.get_formatted()<<']'<<'\n'; 
};