#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    // Testing with vector
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
        vec.push_back(i * 2); // 0, 2, 4, 6, 8, ...

    try {
        std::vector<int>::iterator it = easyfind(vec, 6);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Vector error: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Vector error: " << e.what() << std::endl;
    }


    // Testing with list
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    try {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Found in list: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "List error: " << e.what() << std::endl;
    }

    return 0;
}