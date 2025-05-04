#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
private:

public:
	ScavTrap();
	ScavTrap(std::string Name);
	ScavTrap(const ScavTrap& src);
	ScavTrap& operator=(const ScavTrap& src);
	~ScavTrap();

	void attack(const std::string& target);
	void guardGate();
};


#endif
