#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
protected:
    std::string Name;
	int			Hit_points;
	int			Energy_points;
	int			Attack_damage;
	
public:
    ClapTrap();
	ClapTrap(std::string name, int hp = 10, int ep = 10, int ad = 0);
    ClapTrap(const ClapTrap& copy);
    ClapTrap& operator=(const ClapTrap& obj);
    ~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};



#endif