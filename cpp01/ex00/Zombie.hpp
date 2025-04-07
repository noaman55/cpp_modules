
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
    std::string m_name;
public:
    void announce( void );
    Zombie(std::string name);
    ~Zombie();
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif