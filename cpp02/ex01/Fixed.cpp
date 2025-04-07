#include "Fixed.hpp"
#include <iostream>
#include <math.h>

const int Fixed::bits = 8;

Fixed::Fixed(): m_value (0)
{
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    m_value = value << bits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    m_value = roundf(value * 256);
}

Fixed::Fixed (const Fixed& copy): m_value (copy.m_value)
{
    std::cout << "Copy constructor called" << std::endl;
};

Fixed& Fixed::operator= (const Fixed& fixed_point)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this == &fixed_point)
        return (*this);
        
    m_value = fixed_point.m_value;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (m_value);
}

void Fixed::setRawBits( int const raw )
{
    m_value = raw;
}

float Fixed::toFloat( void ) const
{
    return (m_value / 256.0);
}

int Fixed::toInt( void ) const
{
    return (m_value >> 8);
}

std::ostream& operator<< (std::ostream& out, const Fixed& point)
{
    // if ((point.m_value & 255) == 0)
    //     out << point.toInt();
    // else
        out << point.toFloat();
    return (out);
}