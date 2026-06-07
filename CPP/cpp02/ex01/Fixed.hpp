#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <cmath>
#include <iostream>
#include <ostream>

class Fixed
{
private:
	int rawBits;
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed(const int number);
	Fixed(const float number);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	
	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif