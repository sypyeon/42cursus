#include "Animal.hpp"

Animal::Animal()
{
}

Animal::~Animal()
{
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << this->type << " animal func" << std::endl;
}
