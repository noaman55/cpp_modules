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

bool isChar(std::string input)
{
    if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
    {
        if (input[1] >= 0 && input[1] <= 127)
            return true;
        else
            return false;
    }
    return false;
}

bool isInt(std::string literal)
{
    size_t index = 0;

    while (index < literal.length())
    {
        if (!index && (literal[index] == '-' || literal[index] == '+'))
        {
            index++;
            continue;
        }
        else if (isdigit(literal[index]) == 0)
            return false;
    }
    if (isdigit(literal[literal.length() - 1]) == 0) // for '-' or '+'
        return false;
    return true;
}

bool isFloat(std::string literal)
{
    size_t index = 0;
    int dot_Flag = 0;
    int f_Flag = 0;

    while (index < literal.length())
    {
        if (!index && (literal[index] == '-' || literal[index] == '+'))
        {
            index++;
            continue;
        }
        else if (isdigit(literal[index]) == 0 && literal[index] != 'f' && literal[index] != '.')
            return false;
        else if ((f_Flag && literal[index] == 'f') || (dot_Flag && literal[index] == '.')) // searching for double 'f' or double '.'
            return false;
        else if (!f_Flag && literal[index] == 'f')
            f_Flag = 1;
        else if (!dot_Flag && literal[index] == '.')
            dot_Flag = 1;
        index++;
    }
    return true;
}

bool isDouble(std::string literal)
{
    size_t index = 0;
    int dot_Flag = 0;

    while (index < literal.length())
    {
        if (!index && (literal[index] == '-' || literal[index] == '+'))
        {
            index++;
            continue;
        }
        else if (isdigit(literal[index]) == 0 && literal[index] != '.')
            return false;
        else if (dot_Flag && literal[index] == '.') // searching for double 'f' or double '.'
            return false;
        else if (!dot_Flag && literal[index] == '.')
            dot_Flag = 1;
        index++;
    }
    return true;
}

class error: public std::exception
{
    public:
    const char* what() const throw(){
        return "Invalid input";
    }
};

int Detect_Type(std::string input)
{
    if (isChar(input))
        return CHAR;
    else if (isInt(input))
        return INT;
    else if (isFloat(input))
        return FLOAT;
    else if (isDouble(input))
        return DOUBLE;
    else
        throw error();
    return UNKNOWN;
}


void ScalarConverter::convert(std::string input)
{
    int type;
    try
    {
        type = Detect_Type(input);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return ;
    }
    

    if (type == CHAR)
    {
        
        std::cout << "char: " << input[1] << std::endl;
        std::cout << "int: " << static_cast<int>(input[1]) << std::endl;
        std::cout << "float: " << static_cast<float>(input[1]) << std::endl;
        std::cout << "double: " << static_cast<double>(input[1]) << std::endl;
    }

}
