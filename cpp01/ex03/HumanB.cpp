#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string human_name): name (human_name)
{
    // weapon = new Weapon;
}

HumanB::~HumanB()
{
    // delete weapon;
}

void HumanB::setWeapon(Weapon &weapon_type)
{
    // weapon->setType(weapon_type.getType());
    weapon = &weapon_type;
}

void HumanB::attack()
{
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}