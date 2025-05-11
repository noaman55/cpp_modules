#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Unknown_clap_name")
{
    this->Name = "Unknown";
	Hit_points = FragTrap::Hit_points;
	Energy_points = ScavTrap::Energy_points;
	Attack_damage = FragTrap::Attack_damage;

	std::cout << "DiamondTrap default constructor has been called!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
    this->Name = name;
	Hit_points = FragTrap::Hit_points;
	Energy_points = ScavTrap::Energy_points;
	Attack_damage = FragTrap::Attack_damage;

	std::cout << "DiamondTrap " << Name << " has been constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src): ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	Name = src.Name;
	Hit_points = src.Hit_points;
	Energy_points = src.Energy_points;
	Attack_damage = src.Attack_damage;
	
	std::cout << "DiamondTrap copy constructor has been called!" << std::endl;
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& src)
{
	std::cout << "DiamondTrap assignment operator has been called!" << std::endl;

	if (this == &src)
		return (*this);
	this->Name = src.Name;
	Hit_points = src.Hit_points;
	Energy_points = src.Energy_points;
	Attack_damage = src.Attack_damage;

	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << Name << " has been destroyed." << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name is " << Name << " and my ClapTrap name is " << ScavTrap::Name << std::endl;
}