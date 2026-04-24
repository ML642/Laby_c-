#pragma once 

#include <iostream>
#include <string>


class Subtask{
    private:
        std::string description;
        unsigned int priority;
        bool completed;
    public:
        Subtask(std::string opis, int priority , bool status);
        Subtask(std::string opis,  int priority);
        Subtask(std::string opis);
       // Subtask(std::string&& opus,bool status);

        void mark_completed();

        bool is_completed () const ;
        unsigned int get_priority() const ;
        void print() const;
        
};