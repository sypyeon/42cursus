#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "CALL: WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	std::cout << "CALL: WrongCat copy constructor" << std::endl;
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "CALL: WrongCat copy assignment operator" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "CALL: WrongCat destructor" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Meow! Wrong Meow!" << std::endl;
}
