#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// int main() {
//     Intern someRandomIntern;

//     std::cout << "\n--- Creating Valid Forms ---\n";
//     try {
//         AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "home");
//         delete form1;

//         std::cout << "\n";
//         AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
//         delete form2;

//         std::cout << "\n";
//         AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
//         delete form3;
//     }
//     catch (std::exception& e) {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }

//     std::cout << "\n--- Trying to Create Invalid Form ---\n";
//     try {
//         AForm* form4 = someRandomIntern.makeForm("time travel application", "Marty McFly");
//         delete form4;  // Should not happen
//     }
//     catch (std::exception& e) {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }

//     return 0;
// }

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
            std::cerr << e.what() << std::endl;
        }

        try {
            bob.executeForm(*robotForm);  // Should also fail
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "\n--- Error Case: Executing Unsigned Form ---\n";
        AForm* unexistForm = intern.makeForm("abc", "desert");
        if (!unexistForm)
             std::cerr << "abc form doesn't exist" << std::endl;
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