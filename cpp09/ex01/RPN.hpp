#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>


class error: public std::exception
{
	private:
		std::string str;
	public:
		error(std::string err): str(err) {};
		~error() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {};
		virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {return str.c_str();};
};


class RPN
{
private:
    std::stack<int>		_numbers;
    std::string			_str;
    std::stringstream	_input;
    
public:
    RPN(std::string);
    RPN(const RPN& other);
    RPN& operator= (const RPN& other);
    ~RPN();

    void calcul_rpn();
};




#endif