#include <iostream>
#include "Serializer.hpp"  

int main() {
    Data original;
    original.id = 101;
    original.name = "example";

    uintptr_t raw = Serializer::serialize(&original);

    Data* restored = Serializer::deserialize(raw);

    std::cout << "Original pointer : " << &original << "\n";
    std::cout << "Restored pointer : " << restored << "\n";

    if (restored == &original) {
        std::cout << "✅ Success: Pointers match!\n";
        std::cout << "Restored Data -> id: " << restored->id 
                  << ", name: " << restored->name << "\n";
    } else {
        std::cout << "❌ Error: Pointers do not match.\n";
    }
    return 0;
}