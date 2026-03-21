#include "hello.hpp"


static int HELLO_COUNT=0;

void print(std::string name){
    HELLO_COUNT++;
    std::cout<<HELLO_COUNT<<". Hello "<<name<<'.'<<'\n';
};
