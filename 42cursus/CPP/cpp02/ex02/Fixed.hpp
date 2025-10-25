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

	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);

	bool operator==(const Fixed &compare) const;
	bool operator!=(const Fixed &compare) const;
	bool operator<=(const Fixed &compare) const;
	bool operator>=(const Fixed &compare) const;
	bool operator<(const Fixed &compare) const;
	bool operator>(const Fixed &compare) const;

	Fixed operator*(const Fixed &mult);
	Fixed operator/(const Fixed &div);
	Fixed operator+(const Fixed &add);
	Fixed operator-(const Fixed &sub);

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif