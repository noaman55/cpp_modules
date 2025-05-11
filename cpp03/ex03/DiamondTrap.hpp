#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string Name;
public:
    DiamondTrap();
    DiamondTrap(std::string Name);
    DiamondTrap(const DiamondTrap& src);
    DiamondTrap& operator= (const DiamondTrap& src);
    ~DiamondTrap();

    void attack(const std::string& target);
    void whoAmI();
};

#endif