#include <string>
#include "Contact.hpp"

#include <iostream>
#include <iomanip>
#include <ios>

int Contact::totalNbContacts;

Contact::Contact()
{
    
}

void Contact::set_total_contacts(int value)
{
    totalNbContacts = value;
}

void Contact::set_first_name(std::string name)
{
    first_name = name;
}
void Contact::set_last_name(std::string name)
{
    last_name = name;
}
void Contact::set_nickname(std::string name)
{
    nickname = name;
}
void Contact::set_phone_number(std::string phone_nbr)
{
    phone_number = phone_nbr;
}
void Contact::set_darkest_secret(std::string secret)
{
    darkest_secret = secret;
}

int Contact::get_total_contacts()
{
    return (totalNbContacts);
}

std::string Contact::get_first_name()
{
    return (first_name);
}
std::string Contact::get_last_name()
{
    return (last_name);
}
std::string Contact::get_nickname()
{
    return (nickname);
}
std::string Contact::get_phone_number()
{
    return (phone_number);
}
std::string Contact::get_darkest_secret()
{
    return (darkest_secret);
}

void    Contact::display_contact(int	index)
{
	if (index >= totalNbContacts || index < 0)
	{
		std::cout << "wrong index" << std::endl;
		return ;
	}
	std::cout << "Index      :" << index << std::endl;
	std::cout << "First name :" << first_name << std::endl;
	std::cout << "Last name  :" << last_name << std::endl;
	std::cout << "Nickname   :" << nickname << std::endl;
}

Contact::~Contact()
{
}