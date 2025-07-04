#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat low("LowLevel", 150);
        Bureaucrat mid("MidLevel", 40);
        Bureaucrat high("HighLevel", 1);

        ShrubberyCreationForm shrubForm("home");
        RobotomyRequestForm robotForm("Bender");
        PresidentialPardonForm pardonForm("Noaman");

        std::cout << "\n--- Signing Forms ---\n";
        try {
            low.signForm(shrubForm);  // Should fail
        } catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        mid.signForm(shrubForm);     // Should succeed
        mid.signForm(robotForm);     // Should succeed
        high.signForm(pardonForm);   // Should succeed

        std::cout << "\n--- Executing Forms ---\n";
        try {
            low.executeForm(shrubForm);  // Should fail (grade too low)
        } catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        mid.executeForm(shrubForm);     // Should create file with trees
        mid.executeForm(robotForm);     // Should drill + succeed/fail randomly
        high.executeForm(pardonForm);   // Should pardon target

    } catch (std::exception &e) {
        std::cerr << "\nException caught: " << e.what() << std::endl;
    }

    return 0;
}