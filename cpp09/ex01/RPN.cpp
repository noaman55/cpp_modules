#include "RPN.hpp"

class error: public std::exception
{
	private:
		std::string str;
	public:
		error(std::string err): str(err) {};
		~error() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {};
		virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {return str.c_str();};
};

RPN::RPN(std::string str): _str(str), _input(_str)
{
}

RPN::RPN(const RPN& other):_input(other._str)
{
    _data = other._data;
    _str = other._str;
}

RPN& RPN::operator= (const RPN& other)
{
    if (this != &other)
	{
		_data = other._data;
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
			_data.push(atoi(&s[0]));
		else if (_data.size() > 1)
		{
			int	a = _data.top();
			_data.pop();
			int	b = _data.top();
			_data.pop();
			if (s == "+")
				_data.push(a + b);
			if (s == "-")
				_data.push(b - a);
			if (s == "*")
				_data.push(a * b);
			if (s == "/")
			{
				if (a != 0)
					_data.push(b / a);
				else
					throw error("Error: division by 0");
			}
		}
		else
			throw error("Error: not enough operands");
	}

	if (_data.size() == 1)
		std::cout << _data.top() << std::endl;
	else
		throw error("Error: too much operands");
}