#include "functions/my_header.h"

#include "revision_data.h"

#include <iostream>

int main()
{
    std::cout << VER_FILEVERSION_STR << std::endl;

    print_hello_world();

    return 0;
}
