#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{

	// std::vector<int>::iterator it;
	std::list<int>::iterator it;
	// std::vector<int> v;
	std::list<int> v;

	v.push_back(10);
	v.push_back(25);
	v.push_back(3);
	v.push_back(40);
	v.push_back(9);
	try
	{
		it = easyfind<std::list<int> >(v, 33);
		// it = easyfind<std::vector<int> >(v, 11);
		std::cout << "Number " << *it << " is found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
