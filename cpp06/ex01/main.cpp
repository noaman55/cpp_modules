#include <iostream>
#include "Serializer.hpp"  // Your Serializer class
// #include "Data.hpp"        // Your Data struct

int main() {
    // Create a Data object
    Data original;
    original.id = 101;
    original.name = "example";

    // Serialize its address
    uintptr_t raw = Serializer::serialize(&original);

    // Deserialize it back
    Data* restored = Serializer::deserialize(raw);

    // Test: Check if original and restored point to the same address
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