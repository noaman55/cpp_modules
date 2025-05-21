#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    const int size = 4;
    Animal* animals[size];

    // Creating half dogs, half cats
    std::cout << "\n--- Animal Construction ---\n";
    for (int i = 0; i < size; i++) {
        if (i < size / 2) {
            animals[i] = new Dog();
            animals[i]->getBrain()->setIdea(0, "Chase the cat");
            animals[i]->getBrain()->setIdea(1, "Fetch the ball");
        } else {
            animals[i] = new Cat();
            animals[i]->getBrain()->setIdea(0, "Sleep on the laptop");
            animals[i]->getBrain()->setIdea(1, "Knock over the glass");
        }
    }

    // Show ideas
    std::cout << "\n--- Animal Ideas ---\n";
    for (int i = 0; i < size; i++) {
        std::cout << animals[i]->getType() << " Idea 1: "
                  << animals[i]->getBrain()->getIdea(0) << std::endl;
        std::cout << animals[i]->getType() << " Idea 2: "
                  << animals[i]->getBrain()->getIdea(1) << std::endl;
    }

    // Deep copy test
    std::cout << "\n--- Deep Copy Test ---\n";
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Protect the house");

    Dog copiedDog = originalDog;
    copiedDog.getBrain()->setIdea(0, "Eat treats");

    std::cout << "\n\nOriginal Dog's Idea: "
              << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "\n\nCopied Dog's Idea: "
              << copiedDog.getBrain()->getIdea(0) << std::endl;

    // Clean up
    std::cout << "\n--- Deleting Animals ---\n";
    for (int i = 0; i < size; i++) {
        delete animals[i];
    }

    return 0;
}