#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>

int	main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		_exit(1);
	}
	std::fstream file(av[1]);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		_exit(1);
	}
	return 0;
}
