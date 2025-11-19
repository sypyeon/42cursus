#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "CALL: Cat default constructor" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat &other)
{
	std::cout << "CALL: Cat copy constructor" << std::endl;
	this->brain = new Brain();
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "CALL: Cat copy assignment operator" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		*this->brain = *other.brain;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "CALL: Cat destructor" << std::endl;
	delete this->brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}

Brain *Cat::getBrain()
{
	return this->brain;
}
