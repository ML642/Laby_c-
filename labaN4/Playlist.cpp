#include "Playlist.hpp"
#include "Song.hpp"

Playlist::Playlist():capacity(1),size(0),songs(nullptr){
    songs = new Song[capacity];
};

Playlist::Playlist(int capacity):capacity(capacity),size(0),songs(nullptr){
        Song* songs = new Song[capacity];
        this->songs = songs;
};

Playlist::~Playlist(){
    this->size=0;
    this->capacity=0;
    delete[] this->songs;
    this->songs=nullptr;
};
Playlist& Playlist::operator=(const Playlist& other) {
        
    if(this == &other) return *this;
    delete []songs;

    Song* songs = new Song [other.capacity];

    for(int i=0 ; i < other.get_size();i++){
        songs[i] = other.songs[i];
    };
    this->songs = songs;
    this->size = other.get_size();
    this->capacity = other.capacity;
    
    return *this;
};

Playlist& Playlist::operator=( Playlist&& other) {
        
    if(this == &other) return *this;
    delete[] songs;


    this->songs = other.songs;
    this->size = other.get_size();
    this->capacity = other.capacity;
    
    other.songs = nullptr;
    other.size = 0;
    other.capacity = 0;
    return *this;
}




Playlist::Playlist(const Playlist& other) {

    Song* songs = new Song [other.capacity];

    for(int i=0 ; i < other.get_size();i++){
        songs[i] = other.songs[i];
    };
    this->songs = songs;
    this->size = other.get_size();
    this->capacity = other.capacity; 
};

Playlist::Playlist(Playlist&& other )
{
    this->size = other.size;
    
    this->capacity = other.capacity;

    this->songs = other.songs;

    other.songs = nullptr;
    other.size = 0;
    other.capacity = 0;

}


void Playlist::add_song(const Song& song){
   
    if(this->size == this->capacity){
        Song* songs = new Song[this->capacity*2];

        for(int i=0; i<this->size;i++){
            songs[i] = this->songs[i];
        }
        delete[] this->songs;
        this->songs = songs ;
        this->capacity = this->capacity*2;
    }
    
    this->songs[this->size] = song ;
    
    this->size += 1 ;
};

int Playlist::get_size() const {
    return this->size;
};

void Playlist::print(){
    if(this->size == 0 ){
        std::cout<<"Playlist is empty \n" ;
        return;
    }
    for(int i=0; i<this->get_size();i++){
        this->songs[i].print();  
    }
};

