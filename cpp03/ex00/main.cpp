#include "ClapTrap.hpp"

int main() {
    ClapTrap ct1("Clappy");
    ClapTrap ct2("Trapster");

    ct1.attack("Trapster");
    ct2.takeDamage(0); // Damage is 0 since ct1 has 0 attack damage

    ct2.beRepaired(5);

    for (int i = 0; i < 11; ++i) {
        ct1.attack("Trapster");
    }

    ct1.beRepaired(3); // Should fail due to no energy

    return 0;
}