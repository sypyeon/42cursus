#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "CALL: Dog default constructor" << std::endl;
}

Dog::Dog(const Dog &other)
{
	std::cout << "CALL: Dog copy constructor" << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "CALL: Dog copy assignment operator" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "CALL: Dog destructor" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}
