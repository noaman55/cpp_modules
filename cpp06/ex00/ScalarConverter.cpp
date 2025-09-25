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

class error: public std::exception
{
    public:
    const char* what() const throw(){
        return "Invalid input";
    }
};

class errorFlow: public std::exception
{
    public:
    const char* what() const throw(){
        return "overflow detected";
    }
};

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
    if (literal[literal.length() - 1] == 'f')
        return true;
    return false;
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

int Detect_Type(std::string input)
{
    if (isChar(input))
        return CHAR;
    else if (isInt(input))
        return INT;
    else if (isDouble(input))
        return DOUBLE;
    else if (isFloat(input))
        return FLOAT;
    else
        throw error();
}

void    printChar(std::string literal, int type)
{
    std::stringstream	ss;
	int				    c;

    if (type == CHAR && isprint(literal[1]))   
    std::cout << "char: " << "'" << literal[1] << "'" << std::endl;
    else if (type == CHAR && isprint(literal[1]) == 0)
    std::cout << "char: Non displayable" << std::endl;
    else if (type != CHAR)
    {
        ss << literal;
        ss >> c;
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

void    printInt(std::string literal, int type)
{
    long long val;

    if (type == CHAR)
    {
        std::cout << "int: " << static_cast<int>(literal[1]) << std::endl;
        return ;
    }

    val = atoll(literal.c_str());
    if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
    {
        std::cout << "int: overflow detected" << std::endl;
        return ;
    }
    if (type == INT)
        std::cout << "int: " <<  val << std::endl;
    else if (type == FLOAT)
        std::cout << "int: " << static_cast<int>(strtof(literal.c_str(), NULL)) << std::endl;
    else if (type == DOUBLE)
        std::cout << "int: " << static_cast<int>(strtod(literal.c_str(), NULL)) << std::endl;
}

void    printFloat(std::string literal, int type)
{
    float val;

    if (type == CHAR)
    {
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(literal[1]) << "f" << std::endl;
        return ;
    }
    val = strtof(literal.c_str(), NULL);
    if (val == HUGE_VALF || val ==  -HUGE_VALF)
    {
        std::cout << "float: overflow detected" << std::endl;
        return ;
    }
    else if (type == INT)
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(atoi(literal.c_str())) << "f" << std::endl;
    else if (type == FLOAT)
        std::cout << "float: " << std::fixed << std::setprecision(3) << strtof(literal.c_str(), NULL)<< "f" << std::endl;
    else if (type == DOUBLE)
        std::cout << "float: " << std::fixed << std::setprecision(3) << static_cast<float>(strtod(literal.c_str(), NULL)) << "f" << std::endl;
}

void    printDouble(std::string literal, int type)
{
    if (type == CHAR)
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(literal[1]) << std::endl;
    else if (type == INT)
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(atoi(literal.c_str())) << std::endl;
    else if (type == FLOAT)
        std::cout << "double: " << std::fixed << std::setprecision(3) << static_cast<double>(strtof(literal.c_str(), NULL)) << std::endl;
    else if (type == DOUBLE)
        std::cout << "double: " << std::fixed << std::setprecision(3) << strtod(literal.c_str(), NULL) << std::endl;
}

void	Display(std::string literal, int type)
{
    printChar(literal, type);
    printInt(literal, type);
    printFloat(literal, type);
    printDouble(literal, type);
}

void    detectFlowError(std::string literal, int type)
{
    if (type == INT)
    {
        long long val;

        val = atoll(literal.c_str());
        if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
        {
            std::cout << "int: ";
            throw  errorFlow();
        }
    }
    if (type == FLOAT)
    {
        float val;

        val = strtof(literal.c_str(), NULL);
        if (val == HUGE_VALF || val ==  -HUGE_VALF)
        {
            std::cout << "float: ";
            throw  errorFlow();
        }
    }
    if (type == DOUBLE)
    {
        double val;

        val = strtod(literal.c_str(), NULL);
        if (val == HUGE_VAL || val ==  -HUGE_VAL)
        {
            std::cout << "double: ";
            throw  errorFlow();
        }
    }


}


void    Handling_Special_Cases(std::string literal)
{
    if (literal == "+inf" || literal == "+inff")
    {
        std::cout << "char: impossible \nint: impossible" << std::endl;
        std::cout << "float: inff \ndouble: inf" << std::endl;
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible \nint: impossible" << std::endl;
        std::cout << "float: -inff \ndouble: -inf" << std::endl;
    }
    else if (literal == "nan" || literal == "nanf")
    {
        std::cout << "char: impossible \nint: impossible" << std::endl;
        std::cout << "float: nanf \ndouble: nan" << std::endl;
    }
}

void ScalarConverter::convert(std::string literal)
{
    int type;

    if (literal == "-inf" || literal == "+inf" || literal == "-inff"
        || literal == "+inff" || literal == "nan" || literal == "nanf")
    {
        Handling_Special_Cases(literal);
        return ;
    }
    try
    {
        type = Detect_Type(literal);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return ;
    }
    try
    {
        detectFlowError(literal, type);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return ;
    }
    if (type == CHAR)
		Display(literal, CHAR);
	else if (type == INT)
		Display(literal, INT);
	else if (type == DOUBLE)
		Display(literal, DOUBLE);
	else if (type == FLOAT)
		Display(literal, FLOAT);
}
