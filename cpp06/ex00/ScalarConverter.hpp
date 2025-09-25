#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cfloat>

enum Type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    UNKNOWN
};

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& obj);
    ScalarConverter& operator= (const ScalarConverter& obj);
    ~ScalarConverter();
public:
    static void convert(std::string type);
};

#endif