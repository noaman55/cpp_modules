#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    // Normal creations and signing
    try {
        Bureaucrat bob("Bob", 50);
        Bureaucrat alice("Alice", 1);
        Form taxForm("Tax Form", 55, 30);
        Form passportForm("Passport Form", 1, 1);

        // Test successful sign
        std::cout << std::endl;
        std::cout << bob << std::endl;
        std::cout << taxForm << std::endl;
        bob.signForm(taxForm); // Should succeed
        std::cout << taxForm << std::endl;

        try
        {
            // Test failed sign (grade too low)
            bob.signForm(passportForm); // Should fail
            std::cout << passportForm << std::endl;
        }
        catch(const std::exception& e)
        {
             std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        // Test successful sign with high-grade bureaucrat
        std::cout << std::endl;
        alice.signForm(passportForm); // Should succeed
        std::cout << passportForm << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Invalid Bureaucrat Creation ===" << std::endl;

    try {
        Bureaucrat high("TooHigh", 0); // Invalid grade
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat low("TooLow", 151); // Invalid grade
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Invalid Form Creation ===" << std::endl;

    try {
        Form f1("BadForm1", 0, 100); // Invalid sign grade
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Form f2("BadForm2", 100, 151); // Invalid execute grade
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}