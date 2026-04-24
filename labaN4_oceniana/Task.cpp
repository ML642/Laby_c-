#include "Task.hpp"


Task::Task(std::string opis):description(opis),head(nullptr){};
Task::Task():description(""),head(nullptr){};

Task::~Task(){
    clear();
};

void Task::clear(){
    SubtaskNode* head = this->head;

    if(!head) return;

    while( head ){
        SubtaskNode* next=head->next;
        delete head;
        head = next;
    } 
    this->head = nullptr;
};
void Task::add_subtask(const Subtask& subtask){
    SubtaskNode* head = this->head;
    SubtaskNode* nowy = new SubtaskNode(subtask);
    SubtaskNode* next =nullptr ;
    
     if(head == nullptr){
        this->head = nowy;
        return ;
    }
    if(head->data.get_priority()<subtask.get_priority()){
        this->head = nowy ;
        nowy->next = head ; 
        return ;
    }

    while(head->next && head->next->data.get_priority() >= subtask.get_priority()){
    head = head->next;
}

nowy->next = head->next;
head->next = nowy;
};

bool Task::is_completed() const
{
    SubtaskNode* head = this->head ;
    while(head){
        if(head->data.is_completed() == false){
            return false;
        }
        head=head->next;
    }
    return true ;
}

void Task::complete_subtask(unsigned int index){
    int i = 0 ;
    SubtaskNode* head = this->head; 
    while(head){
        if(i == index){
            head->data.mark_completed();
            i++;    
            return;
        }
        head=head->next;
    }
}

void Task::print() const 
{
    if (this->is_completed() == false ){
        std::cout<<"[ ] ";
    }
    else {
        std::cout<<"[x] ";
    };
    std::cout<<this->description << '\n';

    SubtaskNode* head = this->head;

    while(head){
        std::cout<<'\t'<<'-';
        head->data.print();
        head = head->next;
    }
}


Task& Task::operator=(const Task& other){
      this->description = other.description;
      if( this == &other ) return *this;
      if(!other.head) return *this;

    this->head = new SubtaskNode(other.head->data);

    SubtaskNode* curr = other.head->next;
    SubtaskNode* nowy = this->head;

    while(curr){
        
         nowy->next = new SubtaskNode(curr->data);
        
         nowy= nowy->next; 
        
         curr=curr->next;
         
    }
    return *this;
};

Task& Task::operator=(Task&& other){
    if(this == &other )return *this ;
    this->description = other.description; 
    this->head = other.head;

    //clear(other);
    other.head = nullptr;

    return *this;
};


Task::Task(const Task& other){    
    this->description = other.description;
    if(!other.head) return;

    this->head = new SubtaskNode(other.head->data);

    SubtaskNode* curr = other.head->next;
    SubtaskNode* nowy = this->head;

    while(curr){
        
         nowy->next = new SubtaskNode(curr->data);
        
         nowy= nowy->next; 
        
         curr=curr->next;
         
    }

};
Task::Task(Task&& other){
    this->description = other.description; 
    this->head = other.head;
    //clear(other);
    other.head = nullptr;
}