#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>
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

// int main(int ac, char** av)
// {
// 	(void) ac;
// 	(void) av;
// 	// std::stringstream	str;
// 	// double				nb;

// 	// // std::cout << "string " << av[1] << std::endl;
// 	// str << av[1];
// 	// str >> nb;

// 	// std::cout << "nnnn " <<  nb << std::endl;
//     // std::cout << static_cast<int>(646212.651) << std::endl;

// 	// double myDouble = strtod(av[1], NULL);
// 	// std::cout << std::fixed;
// 	std::cout << static_cast<float>(NAN) << std::endl;
// 	// std::cout << static_cast<double>(214748364.51f) << std::endl;
// 	// std::cout << std::setprecision(3) << std::numeric_limits<float>::max() - 20000 << " kkkk " << std::endl;
// 	// if (strtod(av[1], NULL) <= std::numeric_limits<float>::max())
// 	// 	std::cout << "true" << std::endl;
// 	// else
// 	// 	std::cout << "false" << std::endl;
// 	// std::cout << 3659487241.0 << std::endl;
//     // int myInt = static_cast<int>(myDouble); // myInt will be 3
// 	// std::cout << myInt << std::endl;
// 	// std::cout << static_cast<int>(3659487241.0) << std::endl;
//     return 0;
// }


#include <iostream>
#include <limits>
#include <cmath>

int main() {

int x = 42;
void* p = reinterpret_cast<void*>(x);  // Convert x to a void*

class Base {};
class Derived : public Base {};

// Derived d;
// Base* b = reinterpret_cast<Base*>(&d);  // Convert &d to a pointer to Base

int* pi = reinterpret_cast<int*>(p);  // Convert p back to an int*
std::cout << pi << std::endl;  // Outputs: 42

    return 0;
}