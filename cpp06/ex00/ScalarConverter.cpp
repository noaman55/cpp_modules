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
        index++;
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
    {
        std::cout << "it's an int" << std::endl;
        return INT;
    }
    else if (isFloat(input))
        return FLOAT;
    else if (isDouble(input))
        return DOUBLE;
    else
        throw error();
    return UNKNOWN;
}

void    printChar(std::string literal, int type)
{
    std::stringstream	str;
	int				    c;

    if (type == CHAR && isprint(literal[1]))   
    std::cout << "char: " << "'" << literal[1] << "'" << std::endl;
    else if (type == CHAR && isprint(literal[1]) == 0)
    std::cout << "char: Non displayable" << std::endl;
    else if (type != CHAR)
    {
        str << literal;
        str >> c;
        if (0 <= c && c <= 127 && isprint(c))
        {
            
            std::cout << "char: " << "'" << static_cast<char>(c) << "'" << std::endl;
        }
        else if (0 <= c && c <= 127 && isprint(c) == 0)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
    }
}

void    printfloat(std::string literal, int type)
{
    std::stringstream	str;
	int				    c;

    
    
}

void	convertFromChar(std::string literal)
{
	std::stringstream	str;
	char				c;

	str << literal[1];
	str >> c;
	printChar(literal, CHAR);
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	convertFromInt(std::string literal)
{
	std::stringstream	str;
	int					nb;
	str << literal;
	str >> nb;
    printChar(literal, INT);
	std::cout << "int: " << nb << std::endl;
	std::cout << "float: " << static_cast<float>(nb) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(nb) << std::endl;
}


void	convertFromFloat(std::string literal)
{
	std::stringstream	str;
	float				nb;

	str << literal;
	str >> nb;
    printChar(literal, FLOAT);
	std::cout << "int: " << static_cast<int>(nb) << std::endl;
	std::cout << "float: " << nb << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(nb) << std::endl;
}

void	convertFromDouble(std::string literal)
{
	std::stringstream	str;
	double				nb;

	str << literal;
	str >> nb;
    printChar(literal, DOUBLE);
	std::cout << "int: " << static_cast<int>(nb) << std::endl;
	std::cout << "float: " << static_cast<float>(nb) << "f" << std::endl;
	std::cout << "double: " << nb << std::endl;
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
		convertFromChar(input);
	else if (type == INT)
		convertFromInt(input);
	else if (type == FLOAT)
		convertFromFloat(input);
	else if (type == DOUBLE)
		convertFromDouble(input);
}
