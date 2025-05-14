#include "ClapTrap.hpp"

int main() {
    std::cout << "Creating ClapTrap A...\n";
    ClapTrap a("A");

    std::cout << "\nCreating ClapTrap B...\n";
    ClapTrap b("B");

    std::cout << "\n--- B Attacks A ---\n";
    b.attack("A");
    a.takeDamage(5);

    std::cout << "\n--- A Repairs ---\n";
    a.beRepaired(3);

    std::cout << "\n--- A Attacks B Multiple Times ---\n";
    for (int i = 0; i < 11; ++i) {
        a.attack("B");
    }

    std::cout << "\n--- B Repairs Multiple Times (energy test) ---\n";
    for (int i = 0; i < 12; ++i) {
        b.beRepaired(2);
    }

    std::cout << "\n--- B Takes Fatal Damage ---\n";
    b.takeDamage(100);

    std::cout << "\n--- B Tries to Attack and Repair While Dead ---\n";
    b.attack("A");
    b.beRepaired(10);

    std::cout << "\nDestroying ClapTraps...\n";
    return 0;
}