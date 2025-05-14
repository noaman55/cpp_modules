#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("Unknown", ScavTrap::HP, ScavTrap::EP, ScavTrap::AD)
{
	std::cout << "ScavTrap default constructor has been called!" << std::endl;
}

ScavTrap::ScavTrap(std::string Name): ClapTrap(Name, ScavTrap::HP, ScavTrap::EP, ScavTrap::AD)
{
	std::cout << "ScavTrap " << Name << " has been constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src)
{
	Name = src.Name;
	Hit_points = src.Hit_points;
	Energy_points = src.Energy_points;
	Attack_damage = src.Attack_damage;

	std::cout << "ScavTrap copy constructor has been called!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "ScavTrap assignment operator has been called!" << std::endl;
	
	if (this != &src)
	{	
		Name = src.Name;
		Hit_points = src.Hit_points;
		Energy_points = src.Energy_points;
		Attack_damage = src.Attack_damage;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << Name << " has been destroyed." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (Energy_points > 0 && Hit_points > 0)
    {
        Energy_points--;
        std::cout << "ScavTrap " << Name <<" attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
    }
	else
		std::cout << "ScavTrap " << Name << " can't attack — no energy or hit points left." << std::endl;
}

void ScavTrap::guardGate()
{
	if (Energy_points > 0 && Hit_points > 0)
		std::cout << "ScavTrap " << Name << " is now in Gate keeper mode." << std::endl;
	else
		std::cout << "ScavTrap " << Name << " is not in Gate keeper mode. — no energy or hit points left." << std::endl;
}