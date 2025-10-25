#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
	std::cout << "ScavTrap " << name << " has been created." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " has been destroyed." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->has_ep())
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->ad << " points of damage!" << std::endl;
		--this->ep;
	}
}

void ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap " << this->name << " has taken " << amount << " damage!" << std::endl;
	this->hp -= amount;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->has_ep())
	{
		std::cout << "ScavTrap " << this->name << " has been repaired " << amount << " of HP." << std::endl;
		this->hp += amount;
		--this->ep;
	}
}


void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}
