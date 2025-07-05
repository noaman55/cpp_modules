#include "Serializer.hpp"


Serializer::Serializer()
{
    std::cout << "Serializer default constructor has been called" << std::endl;
}

Serializer::Serializer(const Serializer& )
{
    std::cout << "Serializer copy constructor has been called" << std::endl;
}

Serializer& Serializer::operator= (const Serializer& )
{
    std::cout << "Serializer assignment operator has been called" << std::endl;
    return *this;
}

Serializer::~Serializer()
{
    std::cout << "Serializer destructor has been called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}