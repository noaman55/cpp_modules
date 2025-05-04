#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() {
	std	::cout << "=== Creating ScavTrap ===" << std::endl;
	FragTrap scav("Scavy");

	std::cout << "\n=== Testing ScavTrap Actions ===" << std::endl;
	scav.attack("Intruder");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.highFivesGuys();

	std::cout << "\n=== Creating ClapTrap ===" << std::endl;
	ClapTrap clap("Clappy");

	std::cout << "\n=== Testing ClapTrap Actions ===" << std::endl;
	clap.attack("Enemy");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "\n=== End of main ===" << std::endl;
	return 0;
}