#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "CALL: WrongAnimal default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "CALL: WrongAnimal parameterized constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
	std::cout << "CALL: WrongAnimal copy constructor" << std::endl;
	*this = wrongAnimal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
{
	std::cout << "CALL: WrongAnimal copy assignment operator" << std::endl;
	if (this != &wrongAnimal)
		this->type = wrongAnimal.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "CALL: WrongAnimal destructor" << std::endl;
}

const std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Some wrong generic animal sound..." << std::endl;
}
