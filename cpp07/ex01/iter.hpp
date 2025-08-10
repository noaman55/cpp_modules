#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>


template <typename T>
void iter(T *tab, size_t length, void (*f)(T&))
{
    size_t i = 0;

    while (i < length)
    {
        f(tab[i]);
        i++;
    }
}

#endif