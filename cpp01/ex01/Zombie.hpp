#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <stdlib.h>

class Zombie
{
private:
    std::string m_name;
public:
    void announce( void );
    void setName (std::string name);
    Zombie(std::string name);
    Zombie(void);
    ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif