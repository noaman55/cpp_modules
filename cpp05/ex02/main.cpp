#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

// int main() {
//     try {
//         Bureaucrat bob("Bob", 50);
//         Bureaucrat alice("Alice", 1);
//         Bureaucrat tom("Tom", 150);

//         Form taxForm("Tax Form", 45, 30);
//         Form passportForm("Passport Form", 1, 1);

//         std::cout << bob << std::endl;
//         std::cout << alice << std::endl;
//         std::cout << tom << std::endl;

//         std::cout << taxForm << std::endl;
//         std::cout << passportForm << std::endl;

//         // Bob tries to sign both forms
//         bob.signForm(taxForm);         // Should succeed
//         bob.signForm(passportForm);    // Should fail (grade too low)

//         // Alice tries to sign both forms
//         std::cout << "mlmlmlmlml" << std::endl;
//         alice.signForm(passportForm);  // Should succeed

//         // Tom tries to sign a form with a high requirement
//         tom.signForm(taxForm);         // Should fail

//     } catch (std::exception &e) {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }

//     return 0;
// }


int main() {
    // Normal creations and signing
    try {
        Bureaucrat bob("Bob", 50);
        Bureaucrat alice("Alice", 1);
        Form taxForm("Tax Form", 45, 30);
        Form passportForm("Passport Form", 1, 1);

        // Test successful sign
        std::cout << std::endl;
        std::cout << bob << std::endl;
        std::cout << taxForm << std::endl;
        bob.signForm(taxForm); // Should succeed
        std::cout << taxForm << std::endl;

        // Test failed sign (grade too low)
        bob.signForm(passportForm); // Should fail
        std::cout << passportForm << std::endl;

        // Test successful sign with high-grade bureaucrat
        alice.signForm(passportForm); // Should succeed
        std::cout << passportForm << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception during valid operations: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Invalid Bureaucrat Creation ===" << std::endl;

    try {
        Bureaucrat high("TooHigh", 0); // Invalid grade
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat low("TooLow", 151); // Invalid grade
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Invalid Form Creation ===" << std::endl;

    try {
        Form f1("BadForm1", 0, 100); // Invalid sign grade
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form f2("BadForm2", 100, 151); // Invalid execute grade
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}