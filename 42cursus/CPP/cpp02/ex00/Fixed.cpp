#include "Fixed.hpp"
#include <iostream>

// Default constructor
Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other) : value(other.getRawBits()) {
	std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->value = other.getRawBits();
	}
	return *this;
}

// Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// getRawBits member function
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

// setRawBits member function
void Fixed::setRawBits(int const raw) {
	this->value = raw;
}
