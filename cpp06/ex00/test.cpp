#include <iostream>
#include "ScalarConverter.hpp"  // Your class header


void	convertFromDouble(std::string literal)
{
	std::stringstream	str;
	double				nb;

	str << literal;
	str >> nb;
	std::cout << "char: " << "'" << static_cast<char>(nb) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(nb) << std::endl;
	std::cout << "float: " << static_cast<float>(nb) << std::endl;
	std::cout << "double: " << nb << std::endl;
}

// int main(int ac, char** av)
// {
//     if (ac == 2)
//     {
//         int a = __INT_MAX__;
//         std::string input = av[1];
//         std::cout << a << std::endl;
//         std::cout << "int " << static_cast<char>(333)  << std::endl;
//         std::cout << input << std::endl;
//         // ScalarConverter::convert(input);
//     }

//     return 0;
// }

int main()
{


    std::cout << isprint(500000) << std::endl;


    return 0;
}