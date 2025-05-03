#include "ClapTrap.hpp"

ClapTrap::ClapTrap(/* args */)
{
    std::cout << "ClapTrap " << Name << " has been constructed!" << std::endl;
}

ClapTrap::ClapTrap(std::string name): Name(name), Hit_points(10),
    Energy_points(10), Attack_damage(0)
{
    std::cout << "ClapTrap " << Name << " has been constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    Name = copy.Name;
	Hit_points = copy.Hit_points;
	Energy_points = copy.Energy_points;
	Attack_damage = copy.Attack_damage;

}

ClapTrap& ClapTrap::operator= (const ClapTrap& obj)
{
    if (this == &obj)
        return (*this);

    Name = obj.Name;
	Hit_points = obj.Hit_points;
	Energy_points = obj.Energy_points;
	Attack_damage = obj.Attack_damage;

    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (Energy_points > 0 && Hit_points > 0)
    {
        Energy_points--;
        std::cout << "ClapTrap " << Name <<" attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
    }
	else
		std::cout << "ClapTrap " << Name << "can't attack — no energy or hit points left." << std::endl;
}
    
void ClapTrap::takeDamage(unsigned int amount)
{
	if (Hit_points - amount > 0)
	{
		Hit_points -= amount;
		std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage! Current HP: " << Hit_points << std::endl;
	}
	else
	{
		Hit_points = 0;
		std::cout << "ClapTrap " << Name << " has been destroyed!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (Energy_points > 0 && Hit_points > 0)
    {
        Energy_points--;
        Hit_points += amount;
        std::cout << "ClapTrap " << Name <<" repairs itself for " << amount << " hit points! Current HP: " << Hit_points << std::endl;
    }
    else 
        std::cout << "ClapTrap " << Name << " can't repair — no energy or hit points left." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << Name << " has been destroyed." << std::endl;
}