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
	}
	













    // std::string s;
	// while (std::getline(_input, s, ' '))
	// {
	// 	int a;
	// 	int b;

	// 	// std::cerr << s << " 88" << std::endl;
	// 	if (s.size() == 1 && isdigit(s[0]))
	// 		_data.push(atoi(&s[0]));
	// 	else if ((s == "+" || s == "-" || s == "*" || s == "/") &&  _data.size() > 1)
	// 	{
	// 		a = _data.top();
	// 		_data.pop();
	// 		b = _data.top();
	// 		_data.pop();
	// 	}
	// 	else
	// 	{
	// 		std::cerr << "Error" << std::endl;
	// 		_exit(1);
	// 	}
	// 	if (s == "+")
	// 		_data.push(a + b);
	// 	else if (s == "-")
	// 		_data.push(b - a);
	// 	else if (s == "*")
	// 		_data.push(a * b);
	// 	else if (s == "/")
	// 	{
	// 		if (a == 0)
	// 		{
	// 			std::cerr << "Error: division by 0" << std::endl;
	// 			_exit(1);
	// 		}
	// 		_data.push(b / a);
	// 	}
	// }

	std::cout << _data.top() << std::endl;
}