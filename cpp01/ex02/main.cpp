#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout <<  "The memory address of the string variable: " << &str << "\n";
    std::cout <<  "The memory address held by stringPTR: " << stringPTR << "\n";
    std::cout <<  "The memory address held by stringREF: " << &stringREF << "\n\n\n";

    std::cout <<  "The value of the string variable: " << str << "\n";
    std::cout <<  "The value pointed to by stringPTR: " << *stringPTR << "\n";
    std::cout <<  "The value pointed to by stringREF: " << stringREF << "\n";
    return (0);
}