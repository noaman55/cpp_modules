#include "DiamondTrap.hpp"

int main() {
    std::cout << "\n--- Creating a DiamondTrap ---\n";
    DiamondTrap dt("DiamondBoy");

    std::cout << "\n--- Testing whoAmI() ---\n";
    dt.whoAmI();

    std::cout << "\n--- Testing attack() ---\n";
    dt.attack("EvilBot");

    std::cout << "\n--- Taking damage ---\n";
    dt.takeDamage(30);

    std::cout << "\n--- Repairing ---\n";
    dt.beRepaired(20);

    std::cout << "\n--- Exhausting energy points ---\n";
    for (int i = 0; i < 51; ++i) {
        dt.attack("TargetDummy");
    }

    std::cout << "\n--- Dealing fatal damage and testing behavior ---\n";
    dt.takeDamage(999);
    dt.attack("Ghost");
    dt.beRepaired(10);
    dt.whoAmI();

    std::cout << "\n--- Destroying DiamondTrap ---\n";
    return 0;
}