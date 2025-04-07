#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
    int value;
    static const int bits;
public:
    Fixed();
    Fixed(const Fixed& copy);
    Fixed& operator= (const Fixed& fixed_point);
    ~Fixed();

    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif