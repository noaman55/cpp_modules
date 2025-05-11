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
    std::cout << "🙌 High five, everyone! Let's keep the good vibes going! 🙌" << std::endl;
}