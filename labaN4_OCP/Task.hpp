#pragma once
#include "Subtask.hpp"

struct SubtaskNode {
    Subtask data;
    SubtaskNode* next;
    SubtaskNode(const Subtask& data) : data(data), next(nullptr) {}
};

class Task {
    private:
        std::string description;
        SubtaskNode* head;
    public:
        Task(std::string opis);
        Task();
       ~Task();

        Task& operator=(const Task& other);
        Task& operator=(Task&& other);

        Task(const Task& other);
        Task(Task&& other);
        
        

       void add_subtask(const Subtask& subtask);
       void complete_subtask(unsigned int index);
       bool is_completed() const;
       void clear();
       void print() const;

};