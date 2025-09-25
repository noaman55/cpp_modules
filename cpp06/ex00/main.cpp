#include "ScalarConverter.hpp"

int main(int ac, char** av)
{
    if (ac == 2)
    {
        std::string input = av[1];
        ScalarConverter::convert(input);
    }
    else
    {
        std::cout << "Please insert one argument" << std::endl;
        exit (EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}