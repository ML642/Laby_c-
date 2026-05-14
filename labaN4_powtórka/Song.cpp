#include "Song.hpp"

unsigned int Song::count_songs = 0 ;

Song::Song():title("Untitled"),artist("Unknown"),duration(SongDuration(0,0)){
    Song::count_songs++;
};
Song::Song(std::string tytul , SongDuration czas ,  std::string artist):title(tytul),artist(artist),duration(czas){
    Song::count_songs++;
};
Song::Song(std::string tytul , int  czas ,  std::string artist):title(tytul),artist(artist),duration(SongDuration(czas/60,czas%60)){
    Song::count_songs++;
};
Song::Song(std::string tytul , int  minutes , int seconds , std::string artist):title(tytul),artist(artist),duration(SongDuration(minutes,seconds)){
    Song::count_songs++;
};
Song::Song(std::string title , SongDuration czas):title(title),artist("UNknown"),duration(czas){
    Song::count_songs++;
};
Song::Song(std::string title , int  czas):title(title),artist("UNknown"),duration(SongDuration(czas/60,czas%60)){
    Song::count_songs++;
};

Song::~Song(){
    Song::count_songs -= 1;
}

void Song::print(){
    std::cout<<this->title<<", Artist: "<<this->artist<<' '<<'['<<this->duration.get_formatted()<<']'<<'\n';
};

int Song::get_duration(){
    return this->duration.get_total_seconds();
};
void Song::set_duration(int seconds){
    this->duration = SongDuration(seconds/60,seconds%60);
};
int Song::get_total_songs(){
    return Song::count_songs;
};


std::string Song::get_artist(){
    return this->artist;
};

std::string Song::get_title(){
    return this->title;
}

void Song::set_artist(std::string artist){
    this->artist=artist;
};

void Song::set_title(std::string title){
    this->title=title;
};
