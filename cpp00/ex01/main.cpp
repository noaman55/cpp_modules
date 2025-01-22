#include <iostream>
#include "PhoneBook.hpp"

int	main(int argc, char **argv)
{
    std::string str;
	PhoneBook phonebook;

	std::cin >> str;

	if (str == "ADD")
	    phonebook.addcontact();
    if (str == "SEARCH")
        phonebook.searchcontact();
	return (0);
}