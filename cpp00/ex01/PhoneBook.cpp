#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
    contact_nbr = 0;
}

void    PhoneBook::addcontact()
{
    if (index >= 7)
        index = 0;
    std::string str;
	std::cout << "fill the first name of the contact: ";
	std::cin >> str;
    contact[index].set_first_name(str);
    std::cout << "fill the last name of the contact: ";
	std::cin >> str;
    contact[index].set_last_name(str);
    std::cout << "fill the nickname of the contact: ";
	std::cin >> str;
    contact[index].set_nickname(str);
    std::cout << "fill the phone_number of the contact: ";
	std::cin >> str;
    contact[index].set_phone_number(str);
    std::cout << "fill the darkest_secret of the contact: ";
	std::cin >> str;
    contact[index].set_darkest_secret(str);
    index++;
    if (contact_nbr < 8)
        contact_nbr++;
}

void PhoneBook::searchcontact()
{
    int i;

    i = 0;
    std::cout << "index     |first name|last name|nickname" << std::endl;
    while (i < contact_nbr)
    {
        std::cout << i << contact[i].get_first_name() << "|";
        std::cout << contact[i].get_last_name() << "|";
        std::cout << contact[i].get_nickname() << std::endl;
        i++;
    }
}

PhoneBook::~PhoneBook()
{
}