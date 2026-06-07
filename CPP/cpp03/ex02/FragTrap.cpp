#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
	std::cout << "CALL: FragTrap default constructor." << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
	std::cout << "CALL: FragTrap " << name << " constructor." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << "CALL: FragTrap copy constructor." << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "CALL: FragTrap copy asignment operator." << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hp = other.hp;
		this->ep = other.ep;
		this->ad = other.ad;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "CALL: FragTrap " << name << " destructor." << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->isAlive() && this->hasEp())
	{
		std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->ad << " points of damage!" << std::endl;
		--this->ep;
	}
}

void FragTrap::highFivesGuys(void)
{
	if (this->isAlive() && this->hasEp())
	{
		std::cout << "FragTrap " << this->name << " requests a positive high-five!" << std::endl;
	}
}
