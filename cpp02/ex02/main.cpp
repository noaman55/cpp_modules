#include "Fixed.hpp"
#include <iostream>

int main( void )
{
    Fixed a(0);
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    if (Fixed( 5.05f ) > Fixed( 5.06 ))
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
    
    std::cout << a << std::endl;
    std::cout << --a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;


    std::cout << Fixed( 5.05f ) + Fixed( 2 ) << std::endl;
    std::cout << Fixed( 5.05f ) - Fixed( 2 ) << std::endl;
    std::cout << Fixed( 5.05f ) * Fixed( 2 ) << std::endl;
    std::cout << Fixed( 5.05f ) / Fixed( 2 ) << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}