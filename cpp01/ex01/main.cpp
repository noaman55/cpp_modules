#include "Zombie.hpp"

int main(void)
{
    Zombie *ptr = zombieHorde( 5, "noaman" );

    for (int i = 0; i < 5; i++)
    {
        ptr[i].announce();
    }
    
    delete [] ptr;
    return (0);
}