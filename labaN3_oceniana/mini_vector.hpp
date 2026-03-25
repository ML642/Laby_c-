#pragma once 
#include <iostream>
#include <vector>


struct MiniVector{
    char* elements;
    int size;
    int capacity;
};

void vector_init(MiniVector& a,int b);
void vector_init_fill(MiniVector& minivec,int capacity,char litera);

void vector_print(MiniVector& minivec);

void vector_shrink(MiniVector& minivec,int new_capacity);
void vector_expand(MiniVector& minivec,int new_capacity);
void vector_add(MiniVector& minivec,char s);
void vector_clear(MiniVector& minivec);
void vector_remove(MiniVector& minivec,int position);
void vector_remove_occurrences(MiniVector& minivec,char symbol);