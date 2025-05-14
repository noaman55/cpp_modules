#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	Hit_points = 100;
	Energy_points = 100;
	Attack_damage = 30;
	std::cout << "FragTrap default constructor has been called!" << std::endl;
}

FragTrap::FragTrap(std::string Name): ClapTrap(Name)
{
	Hit_points = 100;
	Energy_points = 100;
	Attack_damage = 30;
	std::cout << "FragTrap " << Name << " has been constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	Name = src.Name;
	Hit_points = src.Hit_points;
	Energy_points = src.Energy_points;
	Attack_damage = src.Attack_damage;

	std::cout << "FragTrap copy constructor has been called!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
	std::cout << "FragTrap assignment operator has been called!" << std::endl;
	
	if (this == &src)
		return *this;
	
	Name = src.Name;
	Hit_points = src.Hit_points;
	Energy_points = src.Energy_points;
	Attack_damage = src.Attack_damage;

	return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << Name << " has been destroyed." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (Energy_points > 0 && Hit_points > 0)
	{
		std::cout << "FragTrap " << Name << " throws a high five! ✋" << std::endl;
		Energy_points--;
	}
	else
		std::cout << "FragTrap " << Name << " is down... no high fives today — no energy or hit points left." << std::endl;
}
    