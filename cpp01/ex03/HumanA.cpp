#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string human_name, Weapon &weapon_type)
    : name (human_name)
    , weapon (weapon_type)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
    std::cout << name << " attacks with their "
        << weapon.getType() << std::endl;
}