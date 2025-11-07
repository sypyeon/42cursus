#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "CALL: Cat default constructor" << std::endl;
}

Cat::Cat(const Cat &cat)
{
	std::cout << "CALL: Cat copy constructor" << std::endl;
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "CALL: Cat copy assignment operator" << std::endl;
	if (this != &cat)
		this->type = cat.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "CALL: Cat destructor" << std::endl;
}



void Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}
