#include "Zombie.hpp"

int main(void)
{
    Zombie *ptr = zombieHorde( 3, "noaman" );

    if (!ptr)
    {
        std::cout << "Allocation failed" << std::endl;
        exit (1);
    }
    for (int i = 0; i < 3; i++)
    {
        ptr[i].announce();
    }
    
    delete [] ptr;
    return (0);
}