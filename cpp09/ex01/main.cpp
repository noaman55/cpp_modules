#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <unistd.h>
#include <stdlib.h>

void	rpn_eval(std::stringstream& input, std::stack<int>& rpn)
{
	std::string s;
	while (std::getline(input, s, ' '))
	{
		int a;
		int b;

		std::cerr << s << " 88" << std::endl;
		if (s.size() == 1 && isdigit(s[0]))
			rpn.push(atoi(&s[0]));
		else if ((s == "+" || s == "-" || s == "*" || s == "/") &&  rpn.size() > 1)
		{
			a = rpn.top();
			rpn.pop();
			b = rpn.top();
			rpn.pop();
		}
		else
		{
			std::cerr << "Error" << std::endl;
			_exit(1);
		}
		if (s == "+")
			rpn.push(a + b);
		else if (s == "-")
			rpn.push(b - a);
		else if (s == "*")
			rpn.push(a * b);
		else if (s == "/")
		{
			if (a == 0)
			{
				std::cerr << "Error: division by 0" << std::endl;
				_exit(1);
			}
			rpn.push(b / a);
		}
	}
}

// void	rpn_eval(std::stringstream& input, std::stack<int>& rpn)
// {
// 	std::string s;
// 	while (std::getline(input, s, ' '))
// 	{
// 		if (s.empty() || s.size() > 1 || (!isdigit(s[0]) && !(s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')))
// 		{
// 			std::cerr << "Error" << std::endl;
// 			 _exit(1);
// 		}
// 		else if (isdigit(s[0]))
// 			rpn.push(atoi(&s[0]));
// 		else if (s == "+" && rpn.size() > 1)
// 		{
// 			int a = rpn.top();
// 			rpn.pop();
// 			int b = rpn.top();
// 			rpn.pop();
// 			rpn.push(a + b);

// 		}
// 		else if (s == "-" && rpn.size() > 1)
// 		{
// 			int a = rpn.top();
// 			rpn.pop();
// 			int b = rpn.top();
// 			rpn.pop();
// 			rpn.push(b - a);
// 		}
// 		else if (s == "*" && rpn.size() > 1)
// 		{
// 			int a = rpn.top();
// 			rpn.pop();
// 			int b = rpn.top();
// 			rpn.pop();
// 			rpn.push(a * b);
// 		}
// 		else if (s == "/" && rpn.size() > 1)
// 		{
// 			int a = rpn.top();
// 			if (a == 0)
// 			{
// 				std::cerr << "Error: division by 0" << std::endl;
// 				_exit(1);
// 			}
// 			rpn.pop();
// 			int b = rpn.top();
// 			rpn.pop();
// 			rpn.push(b / a);
// 		}
// 		else
// 			std::cerr << "Error" << std::endl;
// 	}
// }

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "Please insert all the input inside \" \"" << std::endl;
        _exit(1);
	}
	std::string	input = av[1];
    std::stringstream ss(input);
    std::stack<int> rpn;
	rpn_eval(ss, rpn);
	std::cout << rpn.top() << std::endl;
	return 0;
}