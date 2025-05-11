#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    std::cout << "Creating DiamondTrap.........\n";
    DiamondTrap dt("MonsterX");

    std::cout << "\n--- Status Check ---\n";
    dt.whoAmI();
    std::cout << "Hit Points: " << dt.get_hit() << std::endl;
    std::cout << "Energy Points: " << dt.get_energy() << std::endl;
    std::cout << "Attack Damage: " << dt.get_attack() << std::endl;

    std::cout << "\n--- Action ---\n";
    dt.attack("TargetDummy");

    std::cout << "\nDestroying DiamondTrap.........\n";
    return 0;
}