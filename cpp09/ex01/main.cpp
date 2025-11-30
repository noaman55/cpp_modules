#include "RPN.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "Please insert all the input inside \" \"" << std::endl;
        _exit(1);
	}

	try
	{
		RPN obj(av[1]);
		obj.calcul_rpn();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}