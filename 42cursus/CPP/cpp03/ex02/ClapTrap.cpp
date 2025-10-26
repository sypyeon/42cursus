#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hp = 10;
	this->ep = 10;
	this->ad = 0;
	std::cout << "ClapTrap " << name << " has been created." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " has been destroyed." << std::endl;
}

bool ClapTrap::has_ep()
{
	if (this->ep > 0)
		return true;
	std::cout << "ClapTrap " << this->name << " ran out of energy point...";
	return false;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->has_ep())
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->ad << " points of damage!" << std::endl;
		--this->ep;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " has taken " << amount << " damage!" << std::endl;
	this->hp -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->has_ep())
	{
		std::cout << "ClapTrap " << this->name << " has been repaired " << amount << " of HP." << std::endl;
		this->hp += amount;
		--this->ep;
	}
}
