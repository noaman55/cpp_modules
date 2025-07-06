#include <iostream>
#include "ScalarConverter.hpp"  // Your class header

// int main()
// {
//     const std::string testLiterals[] = {
//         // Char literals
//         "'a'",
//         "'Z'",
//         "'0'",

//         // Int literals
//         "42",
//         "-42",
//         "0",

//         // Float literals
//         "4.2f",
//         "-4.2f",
//         "0.0f",
//         "+inff",
//         "-inff",
//         "nanf",

//         // Double literals
//         "4.2",
//         "-4.2",
//         "0.0",
//         "+inf",
//         "-inf",
//         "nan",

//         // Edge cases / invalid
//         "abc",
//         "9999999999999999999999999999999",
//         "'\\n'"  // This is syntactically tricky, but testing as literal
//     };

//     const int count = sizeof(testLiterals) / sizeof(testLiterals[0]);

//     for (int i = 0; i < count; ++i) {
//         std::cout << "=== Testing: " << testLiterals[i] << " ===" << std::endl;
//         ScalarConverter::convert(testLiterals[i]);
//         std::cout << std::endl;
//     }

//     return 0;
// }

int main(int ac, char** av)
{
    if (ac == 2)
    {
        std::string input = av[1];
        ScalarConverter::convert(input);
    }

    return 0;
}