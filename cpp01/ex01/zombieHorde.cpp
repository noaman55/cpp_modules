
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *ptr = new(std::nothrow) Zombie [N];
    
    if (!ptr)
        return (NULL);
    for (int i = 0; i < N; i++)
    {
        ptr[i].setName(name);
    }
    return (ptr);
}