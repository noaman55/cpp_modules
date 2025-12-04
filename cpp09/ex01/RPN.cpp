#include "RPN.hpp"

RPN::RPN(std::string str): _str(str), _input(_str)
{
}

RPN::RPN(const RPN& other):_input(other._str)
{
    _numbers = other._numbers;
    _str = other._str;
}

RPN& RPN::operator= (const RPN& other)
{
    if (this != &other)
	{
		_numbers = other._numbers;
		_str = other._str;
	}
	return *this;
}


RPN::~RPN()
{
}


void RPN::calcul_rpn()
{

	std::string s;

	if (_str.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw error("Error: invalid character");

	while (_input >> s)
	{
		if (s.size() > 1)
			throw error("Error");
		else if (isdigit(s[0]))
			_numbers.push(atoi(&s[0]));
		else if (!isdigit(s[0]) && _numbers.size() > 1)
		{
			int	a = _numbers.top();
			_numbers.pop();
			int	b = _numbers.top();
			_numbers.pop();
			if (s == "+")
				_numbers.push(a + b);
			if (s == "-")
				_numbers.push(b - a);
			if (s == "*")
				_numbers.push(a * b);
			if (s == "/")
			{
				if (a != 0)
					_numbers.push(b / a);
				else
					throw error("Error: division by 0");
			}
		}
		else
			throw error("Error: not enough operands");
	}

	if (_numbers.size() == 1)
		std::cout << _numbers.top() << std::endl;
	else
		throw error("Error: too much operands");
}