#include "PmergeMe.hpp"
#include <unistd.h>

void	print_list(std::vector<int> &v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

void	parse_args(std::vector<int> &v, std::string args)
{
	std::stringstream	ss(args);
	int					nbr;
	while (ss >> nbr)
	{
		if (std::find(v.begin(), v.end(), nbr) == v.end())
			v.push_back(nbr);
		else
		{
			std::cerr << "Please insert a list of integers to be sorted" << std::endl;
			_exit(1);
		}
	}
}

void	sort_pairs(std::vector<int> &v)
{

	for (size_t i = 0; i < v.size() / 2; i++)
	{
		if (v[2 * i] < v[2 * i + 1])
			std::swap(v[2 * i], v[2 * i + 1]);
	}
	
	
}

int	main(int ac, char** av)
{
	std::vector<int>	v;
	std::string			args;
	std::vector<int>	main;
	std::vector<int>	pend;

	if (ac == 1)
	{
		std::cerr << "Please insert a list of integers to be sorted" << std::endl;
		_exit(1);
	}

	args = av[1];
	if (args.find_first_not_of("0123456789 ") != std::string::npos)
	{
		std::cerr << "Error: invalid character" << std::endl;
		_exit(1);
	}
	parse_args(v, av[1]);
	sort_pairs(v);

	for (size_t i = 0; i < v.size() / 2; i++)
	{
		main.push_back(v[2 * i]);
		pend.push_back(v[2 * i + 1]);
	}
	main.insert(main.begin(), pend.front());
	pend.erase(pend.begin());
	print_list(v);
	print_list(main);
	print_list(pend);
	return 0;
}