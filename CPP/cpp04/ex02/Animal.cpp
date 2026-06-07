#include "Animal.hpp"

Animal::Animal() : type("unknown")
{
	std::cout << "CALL: Animal default constructor" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "CALL: Animal parameterized constructor" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout << "CALL: Animal copy constructor" << std::endl;
	*this = animal;
}

Animal &Animal::operator=(const Animal &animal)
{
	std::cout << "CALL: Animal copy assignment operator" << std::endl;
	if (this != &animal)
		this->type = animal.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "CALL: Animal destructor" << std::endl;
}

const std::string Animal::getType() const
{
	return this->type;
}
