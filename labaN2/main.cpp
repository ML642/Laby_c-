#include <iostream>
#include "vector3.hpp"
#include <vector>
void print_readable_character(std::byte byte)
{
    if (byte >= std::byte{0x20} && byte <= std::byte{0x7E})
        std::cout << static_cast<char>(byte);
    else
        std::cout << ".";  // Non readable character cannot be shown in the console
}

void dump_memory(std::byte* start, size_t count)
{
    const long int window_width = 8;

    // STAGE 3: Implement me!
    // Hint: you can use print_readable_character function to print arbitrary byte as character
}

int main()
{
    std::cout << "STAGE 1" << std::endl;
    l2::Vector3 a;
    l2::Vector3 b;
    l2::Vector3 c;
    
    l2::vector3_init(a,0,0,1);
    l2::vector3_init(b,0,1,0);
    l2::vector3_init(c,1,0,0);

    l2::vector3_mul(a,5);
    l2::vector3_mul(b,3);
    l2::vector3_mul(c,1);

    l2::Vector3* sum=vector3_add(a,  b);
    
    l2::Vector3* result=vector3_add( *sum,c);

    l2::vector3_print(*result);





    

    std::cout << "STAGE 2 and 3" << std::endl;

    const int array_size = 10;

    l2::Vector3 tab[array_size];
    l2::Vector3* tab_dynamic=new l2::Vector3[10];
    std::vector<l2::Vector3> tab_vector;

    for(int i=0;i<array_size;i++){
        l2::Vector3 nowy;
        vector3_init(nowy,i,i,i);
        tab[i]=nowy;
        tab_dynamic[i]=nowy;
        tab_vector.push_back(nowy);
    };

    // STAGE 2: stack, heap and std::vector

    std::cout << "STAGE 4" << std::endl;

    // STAGE 4: HoleyString should be created here

    std::cout << "STAGE 5" << std::endl;

    // STAGE 5: test your memcpy and memmove implementations here

    return 0;
}