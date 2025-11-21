#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

class RPN
{
private:
    std::stack<int>		_data;
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