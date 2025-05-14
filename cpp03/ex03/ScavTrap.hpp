#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
public:

	static const int HP = 100;
	static const int EP = 50;
	static const int AD = 20;

	ScavTrap();
	ScavTrap(std::string Name);
	ScavTrap(const ScavTrap& src);
	ScavTrap& operator=(const ScavTrap& src);
	~ScavTrap();

	void attack(const std::string& target);
	void guardGate();
};


#endif
