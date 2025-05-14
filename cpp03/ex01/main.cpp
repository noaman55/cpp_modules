#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "\n--- Creating a ClapTrap ---\n";
    ClapTrap clap("CL4P-TP");

    std::cout << "\n--- Creating a ScavTrap ---\n";
    ScavTrap scav("SC4V-TP");

    std::cout << "\n--- ClapTrap Attacks ---\n";
    clap.attack("Bandit");
    clap.takeDamage(3);
    clap.beRepaired(2);

    std::cout << "\n--- ScavTrap Attacks ---\n";
    scav.attack("Vault Hunter");
    scav.takeDamage(40);
    scav.beRepaired(25);

    std::cout << "\n--- ScavTrap Enters Guard Mode ---\n";
    scav.guardGate();

    std::cout << "\n--- Testing Energy Depletion on ScavTrap ---\n";
    for (int i = 0; i < 55; ++i) {
        scav.attack("TargetDummy");
    }

    std::cout << "\n--- Testing Behavior When HP is 0 ---\n";
    scav.takeDamage(100);  // Should kill it
    scav.attack("Ghost");
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "\n--- Destroying Objects ---\n";
    return 0;
}