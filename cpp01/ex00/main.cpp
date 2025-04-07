#include "Zombie.hpp"

int main(void)
{
    Zombie *ptr;
    Zombie zombie1 ("noaman");
    zombie1.announce();
    randomChump("mouad");
    ptr = newZombie("forrest");
    ptr->announce();
    delete ptr;
    return (0);
}