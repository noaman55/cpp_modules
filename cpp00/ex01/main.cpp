#include <iostream>
#include <cstdlib>
#include "PhoneBook.hpp"

int	main(void)
{
    std::string	str;
	PhoneBook	phonebook;

	while (1)
	{
		do
		{
			std::cout << "Please enter one of the following commands: ADD, SEARCH or EXIT: ";
			std::cin >> str;
			
		} while (!(str == "ADD" || str == "SEARCH" || str == "EXIT"));

		if (str == "ADD")
			phonebook.addcontact();
		if (str == "SEARCH")
			phonebook.searchcontact();
		if (str == "EXIT")
			exit(0);
	}
	return (0);
}