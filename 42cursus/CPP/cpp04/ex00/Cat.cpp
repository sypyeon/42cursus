#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";

}

Cat::~Cat() {}


void Cat::makeSound()
{
	std::cout << " MEOW!" << std::endl;
}
