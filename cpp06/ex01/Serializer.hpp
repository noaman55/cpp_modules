#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdlib>
#include <iostream>
#include <stdint.h>

typedef struct Data
{
    int id;
    std::string name;
}               Data;

class Serializer 
{
private:
    
public:
    Serializer();
    Serializer(const Serializer& obj);
    Serializer& operator= (const Serializer& obj);
    ~Serializer();

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif