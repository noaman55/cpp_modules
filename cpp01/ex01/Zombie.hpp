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
    void setName (std::string name);
    Zombie(std::string name);
    Zombie(void);
    ~Zombie();
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );
Zombie* zombieHorde( int N, std::string name );

#endif