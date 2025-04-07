#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    Harl obj;

    if (argc != 2)
    {
        std::cout << "please enter one input" << std::endl;
        return (1);
    }

    obj.complain(argv[1]);
    return (0);
}