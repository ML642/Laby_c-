#include "mini_vector.hpp"
static const int  INIT_CAPACITY=5;
void vector_init(MiniVector& minivec,int capacity)
{
    minivec.capacity=capacity;
    minivec.size=0;

    char* elements = new char[capacity];

    minivec.elements=elements;

};

void vector_init_fill(MiniVector& minivec,int capacity,char litera)
{
    minivec.capacity=capacity;
    minivec.size=0;

    char* elements = new char[capacity];

    for(int i=0;i<capacity;i++){
        elements[i]=litera;
    }
    
    minivec.size=capacity;
    minivec.elements=elements;

};
void vector_print(MiniVector& minivec){
    if(minivec.size==0){
        std::cout<<"no elements in vector."<<'\n';
    }
    else {
        std::cout<<'[';
        for(int i=0;i<minivec.size-1;i++){
            std::cout<<minivec.elements[i]<<',';
        }

        std::cout<<minivec.elements[minivec.size-1]<<']'<<'\n';
    }
}

void vector_expand(MiniVector& minivec,int new_capacity){
    if(new_capacity<=minivec.capacity){
        std::cout<<"new capacity is lower than current.\n";
        return;
    }

    char* new_elements=new char[new_capacity];
    for(int i=0;i<minivec.size;i++){
        new_elements[i]=minivec.elements[i];
    }
    delete[] minivec.elements;
    minivec.elements=new_elements;
    minivec.capacity=new_capacity;
}

void vector_shrink(MiniVector& minivec,int new_capacity){
    if(minivec.capacity<=new_capacity){
        std::cout<<"Cannot shrink vector: new capacity is greater than current.\n";
        return;
    }
    if(minivec.size>new_capacity){
        std::cout<<"Cannot shrink vector: there are elements that would be lost in the process.\n";
        return;
    }
        char* new_elements=new char[new_capacity];
    for(int i=0;i<minivec.size;i++){
        new_elements[i]=minivec.elements[i];
    }
    delete[] minivec.elements;
    minivec.elements=new_elements;
    minivec.capacity=new_capacity;
}
void vector_add(MiniVector& minivec,char s){
    if(minivec.size==minivec.capacity){
       vector_expand(minivec,minivec.capacity*2);
        minivec.elements[minivec.size]=s;
        minivec.size++;
        std::cout<<"added "<<s<<'\n';
    }
    else{
        minivec.elements[minivec.size]=s;
        minivec.size++;
        std::cout<<"added "<<s<<'\n';
    }
}
void vector_clear(MiniVector& minivec){
    delete[] minivec.elements;

    minivec.capacity=INIT_CAPACITY;
    minivec.size=0;
}
void vector_remove(MiniVector& minivec,int position){
    minivec.elements[position]=' ';
    if(minivec.capacity/2>=minivec.size){
        vector_shrink(minivec,minivec.size/2);
    }
}
void vector_remove_occurrences(MiniVector& minivec,char symbol){
    int count=0;
    for(int i=0;i<minivec.size;i++){
        
        if(minivec.elements[i]==symbol){
            count++;
        };
        if(minivec.elements[i]==symbol && count>1){
            minivec.elements[i]=' ';
        }
         if(minivec.capacity/2>=minivec.size){
        vector_shrink(minivec,minivec.size/2);
    }
    }

}
