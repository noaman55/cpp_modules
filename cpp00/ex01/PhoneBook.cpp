#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
    contact_nbr = 0;
}

int    PhoneBook::addcontact()
{
    std::string str;
	int	total_contacts;

    if (index > 7)
		index = 0;
	total_contacts = contact[index].get_total_contacts();

	std::cout << "fill the first name of the contact: ";
	if(!std::getline(std::cin, str))
		exit(1);
	if(str.empty())
		return 1;
    contact[index].set_first_name(str);

    std::cout << "fill the last name of the contact: ";
	if(!std::getline(std::cin, str))
		exit(1);
	if(str.empty())
		return 1;
    contact[index].set_last_name(str);

    std::cout << "fill the nickname of the contact: ";
	if(!std::getline(std::cin, str))
		exit(1);
	if(str.empty())
		return 1;
    contact[index].set_nickname(str);

    std::cout << "fill the phone_number of the contact: ";
	if(!std::getline(std::cin, str))
		exit(1);
	if(str.empty())
		return 1;
    contact[index].set_phone_number(str);

    std::cout << "fill the darkest_secret of the contact: ";
	if(!std::getline(std::cin, str))
		exit(1);
	if(str.empty())
		return 1;
    contact[index].set_darkest_secret(str);

    index++;
    if (total_contacts < 8)
	{
    	contact[index].set_total_contacts(total_contacts + 1);
	}

	return 0;
}

void	print_str(std::string str)
{
	int	i;

	i = 0;
	if (str.length() <= 10)
		std::cout << std::setw(10) << str;
	else
	{
		while (i < 9)
			std::cout << str[i++];
		std::cout << ".";
	}
}

void	print_line(int index, std::string str2, std::string str3, std::string str4)
{
	std::cout << "|";
	std::cout << std::setw(10) << index;
	std::cout << "|";
	print_str(str2);
	std::cout << "|";
	print_str(str3);
	std::cout << "|";
	print_str(str4);
	std::cout << "|";
}

void PhoneBook::searchcontact()
{
    int i;
	int	total_contacts;
	std::string index;

    i = 0;
	total_contacts = contact[0].get_total_contacts();
    std::cout << " ___________________________________________" << std::endl;
    std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    while (i < total_contacts)
    {
		print_line(i, contact[i].get_first_name(), contact[i].get_last_name(), contact[i].get_nickname());
        std::cout << std::endl;
        i++;
    }
    std::cout << " -------------------------------------------" << std::endl;
	std::cout << "Please select a contact to display: ";
	if(!std::getline(std::cin, index))
		exit(1);
	if (index.length() == 1 && isdigit(index[0]) && index[0] - '0' < 8)
		i = index[0] - '0';
	else
	{
		std::cout << "invalid index" << std::endl;
		return ;
	}
	contact[i].display_contact(i);
}

PhoneBook::~PhoneBook()
{
}