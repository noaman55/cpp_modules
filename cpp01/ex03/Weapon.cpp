#include "Weapon.hpp"

Weapon::Weapon(std::string type) :type (type)
{
}

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType()
{
    return (type);
}

void Weapon::setType(std::string new_type)
{
    type = new_type;
}