#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ios>

class PhoneBook
{
	private:
		int		index;
		int		contact_nbr;
		Contact	contact[8];
	public:
		int	addcontact();
		void	searchcontact();
		
		PhoneBook();
		~PhoneBook();
};
#endif
