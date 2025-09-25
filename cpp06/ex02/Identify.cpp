#include "Identify.hpp"


Base::~Base()
{
}

Base * generate(void)
{
    int random;

    random = rand();
    if (random % 3 == 0)
        return new A;
    else if (random % 3 == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "The type of the object pointed to by p is: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "The type of the object pointed to by p is: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "The type of the object pointed to by p is: C" << std::endl;
    else
        std::cout << "The type of the object pointed to by p is: Unknown" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "The type of the object pointed to by p is: A" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
    }

    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "The type of the object pointed to by p is: B" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
    }

    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "The type of the object pointed to by p is: C" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
    }
    std::cout << "The type of the object pointed to by p is: Unknown" << std::endl;
}