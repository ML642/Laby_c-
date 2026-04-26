#include "Task.hpp"

Task::Task(std::string opis):head(nullptr),description(opis){};
Task::Task():head(nullptr),description("Brak"){};

Task::~Task(){
    SubtaskNode* curr = this->head;

    while(curr){
        SubtaskNode* free0 = curr->next;
        delete curr;
        curr = free0;
    }
    this->head = nullptr;
};

void Task::add_subtask(const Subtask& subtask){
    SubtaskNode* nowy = new SubtaskNode(subtask);
    SubtaskNode* curr = this->head;

    if(!curr || subtask.get_priority() < curr->data.get_priority()){
        this->head = nowy ;
        nowy->next = curr ;
        return;
    }

    while(curr->next && subtask.get_priority()> curr->data.get_priority() ){
        curr = curr->next;
    }
    
    nowy->next = curr->next;
    curr->next = nowy;

};

void Task::complete_subtask(unsigned int index){
    SubtaskNode* curr = this->head;

    int i = 0 ; 
    while(curr){
        if(i == index){
            curr->data.mark_completed();
        }
        i++;
        curr= curr->next;
    }

};

bool Task::is_completed() const {
    SubtaskNode* curr = this->head;

    
    while(curr){
        if(!(curr->data.is_completed())){
           return  false ;
        }
        
        curr= curr->next;
    }
    return true ;

};

void Task::clear(){
    SubtaskNode* curr = this->head;

    while(curr){
        SubtaskNode* free0 = curr->next;
        delete curr;
        curr = free0;
    }
    this->head = nullptr;
}

void Task::print() const {
    if(this->is_completed()){
        std::cout<<"[X]";
    }   
    else{
        std::cout<<"[ ]";
    }
    std::cout<<" "<<this->description<<'\n';

    SubtaskNode* curr = this->head;

    while(curr){
        std::cout<<"\t -";
        curr->data.print();
        curr = curr->next;
    }

}

Task::Task(const Task& other){
    this->description = other.description;

    SubtaskNode* cur = other.head;

    SubtaskNode* nowy = new SubtaskNode(other.head->data);
    cur = cur->next;

    this->head = nowy;
    while(cur){
        nowy->next = new SubtaskNode(cur->data);
        cur = cur->next;
        nowy = nowy->next;
    }


    
    
}

Task& Task::operator=(const Task& other){
    if(this==&other)return *this;
    this->description = other.description;

    SubtaskNode* cur = other.head;

    SubtaskNode* nowy = new SubtaskNode(other.head->data);
    this->head = nowy;
    cur = cur->next;
    while(cur){

        nowy->next = new SubtaskNode(cur->data);
        cur = cur->next;
        nowy = nowy->next;
    }
    
    return *this;

}

Task::Task( Task&& other){
    this->description = other.description;

    this->head = other.head;

   other.head = nullptr;
}

Task& Task::operator=( Task&& other){
    if(this==&other)return *this;


    this->description = other.description;

    this->head = other.head;

    other.head = nullptr;
    return *this;
}
