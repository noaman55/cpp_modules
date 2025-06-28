#include "Intern.hpp"


Intern::Intern()
{
	std::cout << "Intern default constructor has been called" << std::endl;
}

Intern::Intern(const Intern& )
{
	std::cout << "Intern copy constructor has been called" << std::endl;
}

Intern& Intern::operator= (const Intern& )
{
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor has been called" << std::endl;
}

int get_form( std::string form)
{
	int i = 0;
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	while (i < 3)
	{
		if (forms[i] == form)
		{
			std::cout << "Intern creates " << forms[i] << " form" << std::endl;
			return (i);
		}
		i++;
	}
	std::cout << "Intern can't create " << form << std::endl;
	return (-1);
}

AForm* Intern::makeForm(std::string form, std::string target)
{
	    int		index;	

	index = get_form(form);
    switch (index)
    {
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
		default:
			return NULL;
    }
}


// void Harl::complain( std::string level)
// {
//     int		index;	

// 	index = get_level(level);
//     switch (index)
//     {
// 		case 0:
// 			debug();
// 			/* Fallthrough */
// 		case 1:
// 			info();
// 			/* Fallthrough */
// 		case 2:
// 			warning();
// 			/* Fallthrough */
// 		case 3:
// 			error();
// 			break;
// 		default:
// 			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
//     }
// }

