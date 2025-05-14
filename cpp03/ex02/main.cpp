#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "\n--- Creating a ClapTrap ---\n";
    ClapTrap clap("CL4P-TP");

    std::cout << "\n--- Creating a FragTrap ---\n";
    FragTrap frag("FR4G-TP");

    std::cout << "\n--- ClapTrap Attacks ---\n";
    clap.attack("Training Dummy");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n--- FragTrap Attacks ---\n";
    frag.attack("Mutant Skag");
    frag.takeDamage(20);
    frag.beRepaired(15);

    std::cout << "\n--- FragTrap Requests High Fives ---\n";
    frag.highFivesGuys();

    std::cout << "\n--- Draining FragTrap Energy ---\n";
    for (int i = 0; i < 102; ++i) {
        frag.attack("Target");
    }

    std::cout << "\n--- Killing FragTrap and Testing Behavior ---\n";
    frag.takeDamage(200); // Fatal damage
    frag.attack("Ghost");
    frag.beRepaired(50);
    frag.highFivesGuys();

    std::cout << "\n--- Destroying Objects ---\n";
    return 0;
}