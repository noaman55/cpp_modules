#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
private:
    /* data */
public:
    ScavTrap(/* args */);
    ScavTrap(std::string Name);
    ~ScavTrap();

    void guardGate();
};


#endif
