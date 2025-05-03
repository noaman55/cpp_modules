#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie *ptr;

    ptr = new(std::nothrow) Zombie (name);
    return (ptr);
}
