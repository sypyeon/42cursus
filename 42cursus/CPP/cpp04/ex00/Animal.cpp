#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "CALL: Animal default constructor" << std::endl;
}
Animal::Animal(const Animal &animal)
{
	std::cout << "CALL: Animal default destructor" << std::endl;
}

Animal &operator=(const Animal &animal)
{

}

Animal::~Animal()
{
	std::cout << "Animal default destructor" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << this->type << " goes";
}
