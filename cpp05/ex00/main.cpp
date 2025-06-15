#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    try {
        std::cout << "--- Valid Bureaucrat Creation ---" << std::endl;
        Bureaucrat john("John", 42);
        std::cout << john << std::endl;

        std::cout << "--- Increment Grade ---" << std::endl;
        john.incrementGrade();
        std::cout << "After increment: " << john << std::endl;

        std::cout << "--- Decrement Grade ---" << std::endl;
        john.decrementGrade();
        std::cout << "After decrement: " << john << std::endl;

        std::cout << "--- Create Bureaucrat with Too High Grade ---" << std::endl;
        Bureaucrat boss("Boss", 0); // Should throw
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n--- Create Bureaucrat with Too Low Grade ---" << std::endl;
        Bureaucrat intern("Intern", 151); // Should throw
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n--- Grade Boundary Test: Increment from 1 ---" << std::endl;
        Bureaucrat elite("Elite", 1);
        elite.incrementGrade(); // Should throw
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n--- Grade Boundary Test: Decrement from 150 ---" << std::endl;
        Bureaucrat slacker("Slacker", 150);
        slacker.decrementGrade(); // Should throw
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}