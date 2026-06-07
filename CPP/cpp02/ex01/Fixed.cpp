#include "Fixed.hpp"
#include <iostream>

// Default constructor
Fixed::Fixed() : rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	this->rawBits = number << fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number)
{
	this->rawBits = roundf(number * (1 << fractionalBits));
	std::cout << "Float constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->rawBits = other.getRawBits();
	}
	return *this;
}

// Overload of the insertion operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// getRawBits member function
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits;
}

// setRawBits member function
void Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->rawBits) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return this->rawBits >> fractionalBits;
}
