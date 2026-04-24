#include "Subtask.hpp"

Subtask::Subtask(std::string opis,int priority , bool status):description(opis),priority(priority), completed(status) {};
Subtask::Subtask(std::string opis, int priority ):description(opis),priority(priority), completed(false) {};
Subtask::Subtask(std::string opis ):description(opis),priority(0), completed(false) {};
//Subtask::Subtask(std::string&& opis,bool status ):description(opis),priority(0), completed(status) {};

void Subtask::mark_completed()  {
    completed=true;
};

bool Subtask::is_completed() const {
    return completed;
};

unsigned int Subtask::get_priority() const {
    return priority;
};

void Subtask::print() const {
    if(this->completed){
        std::cout<<"[x]";
    }
    else{
        std::cout<<"[ ]";
    }
    std::cout<<" P:"<<this->priority <<','<<' '<<this->description<<'\n'; 
};