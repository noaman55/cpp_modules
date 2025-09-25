#include "Identify.hpp"

int main()
{
    srand(time(0));  // Seed random number generator

    std::cout << "---- Randomly generating and identifying 10 instances ----\n";
    for (int i = 0; i < 10; ++i) {
        Base* obj = generate();  // Randomly creates A, B, or C
        std::cout << "Object " << i + 1 << " (pointer): ";
        identify(obj);           // Identify using pointer

        std::cout << "Object " << i + 1 << " (reference): ";
        identify(*obj);          // Identify using reference
        std::cout << std::endl;
        delete obj;
    }

    Base* obj = new Base();
    std::cout << "Object " << 11 << " (pointer): ";
    identify(obj);

    std::cout << "Object " << 11 << " (reference): ";
    identify(*obj);
    std::cout << std::endl;
    
    delete obj;
    return 0;
}