#include "Task.hpp"


Task::Task(std::string opis){
    SubtaskNode* head = new Subtask;
    this->description  = opis ;
    this->head = nullptr;
};
Task::~Task(){
    SubtaskNode* head = new Subtask;
    this->description  = ' ' ;
    this->head = nullptr;
};

Task::clear(){
    SubtaskNode* head = this->head;
    while( head ){
        SubtaskNode* next=head->next;
        delete head;
        head = next;
    } 
    this->head = nullptr;
};
void add_subtask(const Subtask& subtask){
    SubtaskNode* head = this->head;

    if(head == nullptr){
        this->head = &subtask;
        return ;
    }

    while(head->data->priority > head->next->data->priority && head->next){
        head = head->next;
    }
}