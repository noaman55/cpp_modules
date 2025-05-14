#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// int main()
// {
//     const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();

//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound(); //will output the cat sound!
//     j->makeSound();
//     meta->makeSound();

//     // const WrongAnimal* wrong = new WrongCat();
//     // wrong->makeSound();
//     return 0;
// }











// int main()
// {
//     const int size = 6;
//     Animal *animals[size];

//     for (int i = 0; i < size; i++)
//     {  
//         if (i < size / 2)
// 			animals[i] = new Dog;
// 		else
// 			animals[i] = new Cat;
//     }

//     for (int i = 0; i < size; i++)
//     {
//         delete animals[i];
//     }
// }














// int main() {
//     const int size = 4;
//     Animal* animals[size];

//     std::cout << "\n--- Creating Animals ---" << std::endl;
//     for (int i = 0; i < size; ++i) {
//         if (i < size / 2)
//             animals[i] = new Dog();
//         else
//             animals[i] = new Cat();
//     }

//     std::cout << "\n--- Making Sounds ---" << std::endl;
//     for (int i = 0; i < size; ++i) {
//         animals[i]->makeSound();
//     }

//     std::cout << "\n--- Deleting Animals ---" << std::endl;
//     for (int i = 0; i < size; ++i) {
//         delete animals[i];
//     }

//     std::cout << "\n--- Deep Copy Test ---" << std::endl;
//     Dog original;
//     Dog copy = original;  // Triggers deep copy constructor

//     return 0;
// }



int main() {
    const int size = 4;
    Animal* animals[size];

    // Creating half dogs, half cats
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