#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
    std::cout << "DEBUG:" << "\n";
    std::cout << "I love having extra bacon for my "
        << "7XL-double-cheese-triple-pickle-specialketchup "
        << "burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "INFO:" << "\n";
    std::cout << "I cannot believe adding extra bacon costs more money. "
        << "You didn't put enough bacon in my burger! If you did, "
        << "I wouldn't be asking for more!" << std::endl;

}

void Harl::warning(void)
{
    std::cout << "WARNING:" << "\n";
    std::cout << "I think I deserve to have some extra bacon for free. "
        << "I've been coming for years whereas you started working "
        << "here since last month." << std::endl;
    
}

void Harl::error(void)
{
    std::cout << "ERROR:" << "\n";
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int get_level( std::string level)
{
    int i = 0;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    while (i < 4)
    {
        if (levels[i] == level)
            return (i);
        i++;
    }
    return (-1);
}

void Harl::complain( std::string level)
{
    int		index;	

	index = get_level(level);
    switch (index)
    {
		case 0:
			debug();
			/* Fallthrough */
		case 1:
			info();
			/* Fallthrough */
		case 2:
			warning();
			/* Fallthrough */
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}