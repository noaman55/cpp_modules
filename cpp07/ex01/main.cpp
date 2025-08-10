#include "iter.hpp"
#include <iostream>

template <typename T>
void printElement(T &element) {
    std::cout << element << " ";
}

// Example function: increment element (only works with numbers)
template <typename T>
void increment(T &element) {
    ++element;
}

// Example function: toUpperCase (only works with char)
void toUpperCase(char &c) {
    if (c >= 'a' && c <= 'z') {
        c = c - ('a' - 'A');
    }
}

int main() {
    // Example 1: integers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Integer array before increment: ";
    iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    iter(intArray, intLen, increment<int>);

    std::cout << "Integer array after increment: ";
    iter(intArray, intLen, printElement<int>);
    std::cout << std::endl << "-------------------------" << std::endl;

    // Example 2: strings
    std::string strArray[] = {"apple", "banana", "cherry"};
    size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "String array: ";
    iter(strArray, strLen, printElement<std::string>);
    std::cout << std::endl << "-------------------------" << std::endl;

    // Example 3: double array
    double doubleArray[] = {1.1, 2.2, 3.3};
    size_t doubleLen = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Double array: ";
    iter(doubleArray, doubleLen, printElement<double>);
    std::cout << std::endl << "-------------------------" << std::endl;

    // Example 4: char array with toUpperCase
    char charArray[] = {'h', 'e', 'l', 'l', 'o'};
    size_t charLen = sizeof(charArray) / sizeof(charArray[0]);

    std::cout << "Char array before toUpperCase: ";
    iter(charArray, charLen, printElement<char>);
    std::cout << std::endl;

    iter(charArray, charLen, toUpperCase);

    std::cout << "Char array after toUpperCase: ";
    iter(charArray, charLen, printElement<char>);
    std::cout << std::endl;

    return 0;
}