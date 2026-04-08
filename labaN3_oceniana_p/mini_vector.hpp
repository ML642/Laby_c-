#pragma once 
#include <iostream>
#include <vector>

static int INIT_CAPACITY=4;

struct MiniVector{
    char* elements;
    int capacity;
    int size;
};
void vector_destroy(MiniVector& vector);
void vector_print(MiniVector& vector);
void vector_init_fill(MiniVector& vector, int capacity , char c);
void vector_init(MiniVector& vector, int capacity);
void vector_shrink(MiniVector& vector, int new_capacity);
void vector_expand(MiniVector& vector,int new_capacity);
void vector_clear (MiniVector& vector);
void vector_add(MiniVector& vector, char nowy_element);

void vector_remove_occurrences(MiniVector& vector,char litera);
void vector_remove(MiniVector& vector, int position);
