#include "my_header.h"

#include <iostream>
#include <vector>

// use C++11
void print_hello_world()
{
    std::vector<char> hel = {'H', 'e', 'l', 'l', 'o', ',',
                             'W', 'o', 'r', 'l', 'd', '!','\n'};

    for(auto i:hel)
        std::cout << i;
}


int my_function(){
    return 1;
}


double square2(double x){
    return x * x;
}
