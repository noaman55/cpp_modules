#include <iostream>
#include "Array.hpp" // Make sure to include the correct header file for your Array class

int main() {
    // Test 1: Create an empty array
    Array<int> arr1;
    std::cout << "Test 1: Empty array created. Size: " << arr1.size() << std::endl;

    // Test 2: Create an array with 5 elements (default initialized)
    Array<int> arr2(-5);
    std::cout << "\nTest 2: Array of 5 elements created. Size: " << arr2.size() << std::endl;
    for (size_t i = 0; i < arr2.size(); ++i) {
        std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
    }

    // Test 3: Copy constructor
    Array<int> arr3 = arr2;
    std::cout << "\nTest 3: Array copied from arr2. Size: " << arr3.size() << std::endl;

    // Modify arr3 to check if it does not affect arr2
    arr3[0] = 99;
    std::cout << "arr2[0] after modification to arr3: " << arr2[0] << std::endl;
    std::cout << "arr3[0] after modification: " << arr3[0] << std::endl;

    // Test 4: Assignment operator
    Array<int> arr4;
    arr4 = arr2;
    std::cout << "\nTest 4: Array assigned from arr2. Size: " << arr4.size() << std::endl;

    // Modify arr4 to check if it does not affect arr2
    arr4[1] = 88;
    std::cout << "arr2[1] after modification to arr4: " << arr2[1] << std::endl;
    std::cout << "arr4[1] after modification: " << arr4[1] << std::endl;

    // Test 5: Accessing out-of-bounds element (should throw exception)
    try {
        std::cout << "arr2[10]: " << arr2[10] << std::endl;  // Out of bounds
    } catch (const std::exception& e) {
        std::cout << "\nTest 5: Exception caught: " << e.what() << std::endl;
    }

    return 0;
}