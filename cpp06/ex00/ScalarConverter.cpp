#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter default constructor has been called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& )
{
    std::cout << "ScalarConverter copy constructor has been called" << std::endl;
}

ScalarConverter& ScalarConverter::operator= (const ScalarConverter& )
{
    std::cout << "ScalarConverter assignment operator has been called" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor has been called" << std::endl;
}

void ScalarConverter::convert(std::string type)
{
    std::cout << "ScalarConverter destructor has been called" << std::endl;
}