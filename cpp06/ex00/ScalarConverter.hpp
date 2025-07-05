#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <iostream>

class ScalarConverter
{
private:
    
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& obj);
    ScalarConverter& operator= (const ScalarConverter& obj);
    ~ScalarConverter();

    static void convert(std::string type);
};

#endif