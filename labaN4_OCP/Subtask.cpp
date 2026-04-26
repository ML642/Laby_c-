#include "Subtask.hpp"

Subtask::Subtask(std::string opis):description(opis),priority(0),completed(false){};
Subtask::Subtask(std::string opis,int priority):description(opis),priority(priority),completed(false){};
Subtask::Subtask(std::string opis, int priority , bool completed):description(opis),priority(priority),completed(completed){};


void Subtask::print() const{
    if(this->completed){
        std::cout<<"[X]";
    }
    else {
        std::cout<<"[ ]";
    }
    std::cout<<" P: "<< this->priority << ',' <<' '<< this->description<<'\n';
}

void Subtask::mark_completed(){
    this->completed = true;
}
bool Subtask::is_completed() const {
    if(this->completed)return true ;
    return false ;
}
unsigned int Subtask::get_priority() const {
    return this->priority;
}