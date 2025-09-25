#include <iostream>
#include <string>
#include "MutantStack.hpp" // assuming you implemented this

// int main() {
//     MutantStack<int> mstack;

//     mstack.push(5);
//     mstack.push(17);

//     std::cout << "Top: " << mstack.top() << std::endl; // 17
//     mstack.pop();
//     std::cout << "Size after pop: " << mstack.size() << std::endl; // 1

//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     mstack.push(0);

//     std::cout << "\nIterating through stack elements:\n";
//     for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
//         std::cout << *it << std::endl;
//     }

//     std::cout << "\nReverse iteration:\n";
//     for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
//         std::cout << *rit << std::endl;
//     }

//     // Copy constructor & assignment test
//     MutantStack<int> copyStack = mstack;
//     std::cout << "\nCopy stack contents:\n";
//     for (MutantStack<int>::iterator it = copyStack.begin(); it != copyStack.end(); ++it) {
//         std::cout << *it << std::endl;
//     }

//     // Test with another type
//     MutantStack<std::string> strStack;
//     strStack.push("Hello");
//     strStack.push("World");
//     std::cout << "\nString stack contents:\n";
//     for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it) {
//         std::cout << *it << std::endl;
//     }

//     return 0;
// }


int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    std::cout << s.size() << std::endl;
    return 0;
}