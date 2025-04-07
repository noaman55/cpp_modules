#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
private:
    std::string type;
public:
    Weapon(std::string weapon_type);
    Weapon();
    ~Weapon();

    const std::string& getType();
    void setType(std::string new_type);
};

#endif