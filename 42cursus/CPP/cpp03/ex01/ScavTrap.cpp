#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->name = "ScavTrap";
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
	std::cout << "CALL: ScavTrap default constructor." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
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
		this->hp = 100;
		this->ep = 50;
		this->ad = 20;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " has been destroyed." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->hasEp())
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->ad << " points of damage!" << std::endl;
		--this->ep;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}
