#include "ScavTrap.hpp"

ScavTrap::ScavTrap(/* args */)
{
}

ScavTrap::ScavTrap(std::string Name):ClapTrap(Name)
{
	Hit_points = 100;
	Energy_points = 50;
	Attack_damage = 20;
	std::cout << "ScavTrap " << Name << " has been constructed!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << Name << " has been destroyed." << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << Name << "  is now in Gate keeper mode." << std::endl;
}