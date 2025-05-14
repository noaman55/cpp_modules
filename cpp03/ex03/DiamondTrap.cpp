#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Unknown_clap_name", FragTrap::HP, ScavTrap::EP, FragTrap::AD)
{
    this->Name = "Unknown";
	std::cout << "DiamondTrap default constructor has been called!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name", FragTrap::HP, ScavTrap::EP, FragTrap::AD)
{
    this->Name = name;
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

	if (this != &src)
	{
		this->Name = src.Name;
		Hit_points = src.Hit_points;
		Energy_points = src.Energy_points;
		Attack_damage = src.Attack_damage;
	}
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
	std::cout << "The object's DiamondTrap name is " << Name << " and his ClapTrap's name is " << ClapTrap::Name << std::endl;
}