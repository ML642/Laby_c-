#include "mini_vector.hpp"


void vector_init(MiniVector& vector, int capacity){
    vector.size=0;
    vector.capacity=capacity;

    char *elements=new char[capacity];
    vector.elements=elements;
};
void vector_init_fill(MiniVector& vector, int capacity , char c){
    vector.size=capacity;
    vector.capacity=capacity;

    char *elements=new char[capacity];

    for(int i=0; i< capacity;i++){
        elements[i]=c;
    }
    vector.elements=elements;
};
void vector_print(MiniVector& vector){
    if(vector.size==0){
        std::cout<<"no elements in vector"<<'\n';
        return;
    }
    for(int i=0;i<vector.size-1;i++){
        std::cout<<vector.elements[i]<<',';
    }
    std::cout<<vector.elements[vector.size-1]<<'\n';
};

void vector_destroy(MiniVector& vector){
    vector.size=0;
    vector.capacity=0;
    
    delete[] vector.elements;
};


void vector_expand(MiniVector& vector,int new_capacity){
    if(vector.capacity>=new_capacity){
        std::cout<<"new capacity is lower than current.\n";
        return;
    };

    
    char* nowy_vector = new char[new_capacity];
    
    for(int i=0;i<vector.size;i++){
        nowy_vector[i]=vector.elements[i];
    };
    delete[] vector.elements;

    vector.elements=nowy_vector;
    vector.capacity=new_capacity;
}
void vector_shrink(MiniVector& vector, int new_capacity){
    if(vector.capacity<=new_capacity){
        std::cout<<"new capacity is greater than current.\n";
        return;
    };
    if(vector.size> new_capacity){
        std::cout<<"there are elements that would be lost in the process.\n";
        return;
    };

    vector.capacity=new_capacity;
   
    char* nowy_vector = new char[new_capacity];
    
    for(int i=0;i<vector.size;i++){
        nowy_vector[i]=vector.elements[i];
    };
    delete[] vector.elements;

    vector.elements=nowy_vector;
    vector.capacity=new_capacity;
};

void vector_add(MiniVector& vector, char nowy_element){
    if(vector.size<vector.capacity){
        vector.elements[vector.size]=nowy_element;
        vector.size++;
    }
    else {
        int new_capacity=vector.capacity*2;
        
        char* nowy_vector = new char[new_capacity];
        
        for(int i=0;i<vector.size;i++){
            nowy_vector[i]=vector.elements[i];
        };
        nowy_vector[vector.size]=nowy_element;
        vector.size+=1;

        delete[] vector.elements;

        vector.elements=nowy_vector;
        vector.capacity=new_capacity;
    };
    std::cout<<"added " << nowy_element<<'\n';

};

void vector_clear (MiniVector& vector){
    int new_capacity=INIT_CAPACITY;
      char* nowy_vector = new char[new_capacity];
        
    
     

        delete[] vector.elements;

        vector.elements=nowy_vector;
        vector.size=0;
        vector.capacity=new_capacity;
};

void vector_remove(MiniVector& vector, int position){
    if(position < 0 || position > vector.size){
    std::cout<<"The requested element index is exceeding vector size. (Vector size:"<<vector.size<<". Requested idx for element removal:"
    <<position<<std::endl;
    return;
    };
    

    for(int i=position-1;i<vector.size-1;i++){
        char temp = vector.elements[i] ;
        vector.elements[i] = vector.elements[i+1];
        vector.elements[i+1]=temp;
    };
    vector.size-=1;

    if(vector.size * 2 < vector.capacity){
        vector.capacity=(int) vector.capacity/2;
    };
} ;

void vector_remove_occurrences(MiniVector& vector,char litera){
    for(int i=0;i<vector.size;i++){
        if(vector.elements[i]==litera){
            vector_remove(vector,i);
        }
    }
}