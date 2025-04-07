#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon& weapon;
public:
    HumanA(std::string human_name, Weapon &weapon_type);
    ~HumanA();

    void attack();
};
    
#endif