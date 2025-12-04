#include "RPN.hpp"

int main(int ac, char** av)
{
	try
	{
		if (ac != 2)
			throw error("Please insert all the input inside \" \"");
			
		RPN obj(av[1]);
		obj.calcul_rpn();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}