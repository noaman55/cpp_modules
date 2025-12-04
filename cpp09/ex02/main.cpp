#include "PmergeMe.hpp"

int	main(int ac, char** av)
{
	std::string			args;
	PmergeMe			obj;
	
	try
	{
		if (ac == 1)
			throw error("Please insert a list of integers to be sorted");
	
		obj.parse_args(av);
		obj.sort_vect();
		obj.sort_deque();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}