#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "CALL: WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat)
{
	std::cout << "CALL: WrongCat copy constructor" << std::endl;
	*this = wrongCat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat)
{
	std::cout << "CALL: WrongCat copy assignment operator" << std::endl;
	if (this != &wrongCat)
		this->type = wrongCat.type;
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
