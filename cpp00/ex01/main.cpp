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
			if(!std::getline(std::cin, str))
				exit(1);
			if (!(str == "ADD" || str == "SEARCH" || str == "EXIT"))
				std::cout << "Invalid command" << std::endl;
		} while (!(str == "ADD" || str == "SEARCH" || str == "EXIT"));

		if (str == "ADD")
		{
			if (phonebook.addcontact() == 1)
				std::cout << "Invalid input" << std::endl;
		}
		else if (str == "SEARCH")
			phonebook.searchcontact();
		else if (str == "EXIT")
			exit(0);
	}
	return (0);
}