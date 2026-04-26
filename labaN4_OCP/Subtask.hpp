#pragma once

#include <string>
#include <iostream>

class Subtask{
    private:
        std::string description;
        unsigned int priority;
        bool completed;
    public:
        Subtask(std::string opis , int priorytet , bool ukonczenie);
        Subtask(std::string opis , int priorytet);
        Subtask(std::string opis );
        
        void mark_completed();
        bool is_completed() const ;
        unsigned int get_priority() const ;
        void print() const ;



};