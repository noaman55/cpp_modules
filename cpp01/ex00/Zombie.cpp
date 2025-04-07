#include "Zombie.hpp"

void    Zombie::announce( void )
{
    std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << "\n";
}
Zombie::Zombie(std::string name): m_name (name)
{
}

Zombie::~Zombie()
{
    std::cout << "zombie " << m_name << " has been destroyed" << "\n";
}