#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Intern intern;
        Bureaucrat alice("Alice", 1);       // Highest rank — can sign/execute anything
        Bureaucrat bob("Bob", 130);         // Can only handle Shrubbery (signing)
        Bureaucrat carol("Carol", 40);      // Can handle Robotomy

        std::cout << "\n--- Intern Creating Forms ---\n";
        AForm* shrubForm = intern.makeForm("shrubbery creation", "garden");
        AForm* robotForm = intern.makeForm("robotomy request", "Bender");
        AForm* pardonForm = intern.makeForm("presidential pardon", "Ford Prefect");

        std::cout << "\n--- Signing Forms ---\n";
        alice.signForm(*pardonForm);    // Should succeed
        bob.signForm(*shrubForm);       // Should succeed
        carol.signForm(*robotForm);     // Should succeed

        std::cout << "\n--- Executing Forms ---\n";
        alice.executeForm(*pardonForm); // Should succeed
        bob.executeForm(*shrubForm);    // Should succeed
        carol.executeForm(*robotForm);  // Should succeed, 50% chance

        std::cout << "\n--- Error Case: Too Low to Sign or Execute ---\n";
        try {
            bob.signForm(*robotForm);  // Should fail (not enough grade)
        } catch (std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        bob.executeForm(*robotForm);  // Should also fail

        std::cout << "\n--- Error Case: Executing Unsigned Form ---\n";
        AForm* unsignedForm = intern.makeForm("shrubbery creation", "desert");
        try {
            alice.executeForm(*unsignedForm);  // Should throw "Form not signed"
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        delete unsignedForm;

        // Clean up
        delete shrubForm;
        delete robotForm;
        delete pardonForm;

    } catch (std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
    }

    return 0;
}