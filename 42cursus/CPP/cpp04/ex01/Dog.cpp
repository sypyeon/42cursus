#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "CALL: Dog default constructor" << std::endl;
}

Dog::Dog(const Dog &dog)
{
	std::cout << "CALL: Dog copy constructor" << std::endl;
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "CALL: Dog copy assignment operator" << std::endl;
	if (this != &dog)
		this->type = dog.type;
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
