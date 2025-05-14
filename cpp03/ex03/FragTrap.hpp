#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
public:

	static const int HP = 100;
	static const int EP = 100;
	static const int AD = 30;

	FragTrap();
	FragTrap(std::string Name);
	FragTrap(const FragTrap& src);
	FragTrap& operator=(const FragTrap& src);
	~FragTrap();

	void highFivesGuys(void);
};


#endif
