#include "Playlist.hpp"

Playlist::Playlist(int capacity):capacity(capacity), size(0){
    this->songs= new Song[capacity];
};


Playlist::Playlist():capacity(1), size(0){
    this->songs= new Song[capacity];
};

void  Playlist::add_song(const Song& song){
    if(this->capacity == this->size){
        int new_capacity = this->capacity * 2 ;

        Song* nowy_play = new Song[new_capacity];

        for(int i = 0 ; i < this->size;i++){
            nowy_play[i] = this->songs[i];
        }

        delete[] this->songs;
        this->songs = nowy_play;
        this->capacity = this->capacity*2;
    }
    this->songs[this->size] = song;
    this->size+=1;
};

int Playlist::get_size(){
    return this->size;
};
void Playlist::print(){
    for(int i = 0 ; i< this->size;i++){
        std::cout<<i<<". ";
        this->songs[i].print();
    }
};
Playlist& Playlist::operator=(Playlist& other){
    if(this==&other){return *this;}
    Song* nowy_play = new Song[other.capacity];

    for(int i = 0 ; i < other.size;i++){
            nowy_play[i] = other.songs[i];
        }

    delete[] this->songs;
    this->songs = nowy_play;
    this->capacity = other.capacity;
    this->size = other.size;
    return *this;
};



Playlist& Playlist::operator=(const Playlist& other){
    if(this==&other){return *this;}
    Song* nowy_play = new Song[other.capacity];

    for(int i = 0 ; i < other.size;i++){
            nowy_play[i] = other.songs[i];
        }

    this->songs = nowy_play;
    this->capacity = other.capacity;
    this->size = other.size;
    return *this;
};



Playlist& Playlist::operator=(Playlist&& other){
    if(this==&other){return *this;}
   
    delete[] this->songs;
    this->songs = other.songs;
    this->capacity = other.capacity;
    this->size = other.size;
    return *this;
};

Playlist::Playlist(const Playlist& other ){
    
    Song* nowy_play = new Song[other.capacity];

    for(int i = 0 ; i < other.size;i++){
            nowy_play[i] = other.songs[i];
        }

    this->songs = nowy_play;
    this->capacity = other.capacity;
    this->size = other.size;
}

Playlist::Playlist(Playlist&& other ){
    
    this->songs = other.songs;
    this->capacity = other.capacity;
    this->size = other.size;
}
