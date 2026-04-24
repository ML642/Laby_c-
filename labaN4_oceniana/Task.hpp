#pragma once
#include "Subtask.hpp"
#include "string"

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
        Task(std::string s);
        ~Task();

        void add_subtask(const Subtask& subtask);
        void complete_subtask(unsigned int index);
        bool is_completed() const;
        void clear();
        void print() const ;
};