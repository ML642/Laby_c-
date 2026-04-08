#include <iostream>
#include "vector3.hpp"
#include "holey_string.hpp"
#include <iomanip>

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

    std::byte* end= count + start;


    for(std::byte* i=start; i<end; i+=window_width){
        int max=std::min(end-i,window_width);

        std::cout<< std::hex<< i <<':'<<" ";
        for(int j=0;j<max;j++){
            std::cout << std::setfill('0') << std::setw(2) << std::hex << static_cast<unsigned int>(*(i + j))
                      << " ";
        }
        std::cout<<'|';

        for(int j=0; j < max ; j++){
            print_readable_character(*(i+j));
        }
        std::cout<<'|' <<std::endl;
    }
    std::cout<<start<<'\n';
    // STAGE 3: Implement me!
    // Hint: you can use print_readable_character function to print arbitrary byte as character
}

int main()
{
    std::cout << "STAGE 1" << std::endl;

     l2::Vector3 vec1;
     l2::Vector3 vec2;
     l2::Vector3 vec3;

    l2::vector3_init(vec1,1,0,0);
    l2::vector3_init(vec2,0,1,0);
    l2::vector3_init(vec3,0,0,1);

    l2::vector3_mul(vec1,3);
    l2::vector3_mul(vec2,5);
    l2::vector3_mul(vec3,7);

    const  l2::Vector3* vec4=l2::vector3_add( vec1,  vec2);
    const l2::Vector3*  vec5=l2::vector3_add( *vec4,  vec3);

    l2::vector3_print(*vec5);
    
    delete vec4;
    delete vec5;
    std::cout<<'\n';
    std::cout << "STAGE 2 and 3" << std::endl;
    
  
    
    const int array_size = 10;
    // STAGE 2: stack, heap and std::vector
   
    l2::Vector3* tablica_dynamiczna = new l2::Vector3[array_size];
   
    l2::Vector3 tablica_statyczna[array_size];
    std::vector<l2::Vector3> tablica_wektorowa;

    for(int i=0;i<array_size;i++){
        l2::Vector3 vec={static_cast<double>(i),static_cast<double>(i),static_cast<double>(i)};
        tablica_wektorowa.push_back(vec);
        tablica_dynamiczna[i]=vec;
        tablica_statyczna[i]=vec;
        //l2::vector3_print(vec);
    }

    dump_memory(reinterpret_cast<std::byte*> (tablica_dynamiczna),sizeof(l2::Vector3)*array_size);


    delete [] tablica_dynamiczna;
    std::cout << "STAGE 4" << std::endl;

    l2::HoleyString some_string;

    l2::holey_string_assign(some_string,"hello");
    l2::holey_string_assign(some_string,"world");


    l2::holey_string_print(some_string);

    dump_memory(reinterpret_cast<std::byte*>(&some_string),sizeof(l2::HoleyString));
    std::cout << "STAGE 5" << std::endl;

    // STAGE 5: test your memcpy and memmove implementations here

    return 0;
}