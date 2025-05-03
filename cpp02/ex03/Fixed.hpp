#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int 				m_val;
		static const int	frac_bits = 8;

	public:
		Fixed();
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& copy);

        bool operator>(const Fixed& point) const;
        bool operator<(const Fixed& point) const;
        bool operator>=(const Fixed& point) const;
        bool operator<=(const Fixed& point) const;
        bool operator==(const Fixed& point) const;
        bool operator!=(const Fixed& point) const;

        Fixed operator+(const Fixed& point) const;
        Fixed operator-(const Fixed& point) const;
        Fixed operator*(const Fixed& point) const;
        Fixed operator/(const Fixed& point) const;

		Fixed operator++(void);
		Fixed operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		~Fixed();

		int					getRawBits( void ) const;
		void				setRawBits( int const raw );
		float				toFloat(void) const;
		int					toInt(void) const;
		static Fixed&		min(Fixed& a, Fixed&b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&		max(Fixed& a, Fixed&b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& point);

#endif