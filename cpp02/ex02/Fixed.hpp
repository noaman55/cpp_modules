#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int m_value;
    static const int bits;
public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& copy);
    Fixed& operator= (const Fixed& fixed_point);
    ~Fixed();

    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
    friend std::ostream& operator<< (std::ostream& out, const Fixed& point);
};

#endif