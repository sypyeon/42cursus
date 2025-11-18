#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
	std::cout << "CALL: ScavTrap default constructor." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
	std::cout << "CALL: ScavTrap " << name << " constructor." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "CALL: ScavTrap copy constructor." << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "CALL: ScavTrap copy assignment operator." << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hp = other.hp;
		this->ep = other.ep;
		this->ad = other.ad;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "CALL: ScavTrap " << name << " destructor." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->isAlive() && this->hasEp())
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->ad << " points of damage!" << std::endl;
		--this->ep;
	}
}

void ScavTrap::guardGate()
{
	if (this->isAlive() && this->hasEp())
	{
		std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
		--this->ep;
	}
}
