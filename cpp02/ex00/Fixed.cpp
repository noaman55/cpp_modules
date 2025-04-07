#include "Fixed.hpp"
#include <iostream>

const int Fixed::bits = 8;

Fixed::Fixed(): value (0)
{
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed (const Fixed& copy): value (copy.value)
{
    std::cout << "Copy constructor called" << std::endl;
};

Fixed& Fixed::operator= (const Fixed& fixed_point)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this == &fixed_point)
        return (*this);
        
    value = fixed_point.value;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

void Fixed::setRawBits( int const raw )
{
    value = raw;
}