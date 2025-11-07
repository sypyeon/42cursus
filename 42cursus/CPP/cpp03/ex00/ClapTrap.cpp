#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "ClapTrap";
	this->hp = 10;
	this->ep = 10;
	this->ad = 0;
	std::cout << "CALL: ClapTrap default constructor." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hp = 10;
	this->ep = 10;
	this->ad = 0;
	std::cout << "CALL: ClapTrap " << name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "CALL: ClapTrap copy constructor." << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "CALL: ClapTrap copy assignment operator." << other.name << std::endl;
	if (this != &other)
		this->name = other.name;
	this->hp = 10;
	this->ep = 10;
	this->ad = 0;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "CALL: ClapTrap " << name << " has been destroyed." << std::endl;
}

bool ClapTrap::isAlive()
{
	if (this->hp > 0)
		return true;
	std::cout << "ClapTrap " << this->name << " ran out of hit points...";
	return false;
}

bool ClapTrap::hasEp()
{
	if (this->ep > 0)
		return true;
	std::cout << "ClapTrap " << this->name << " ran out of energy points...";
	return false;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->hasEp() && this->isAlive())
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->ad << " points of damage!" << std::endl;
		--this->ep;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->hp -= amount;
	std::cout << "ClapTrap " << this->name << " has taken " << amount << " damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hasEp() && this->isAlive())
	{
		this->hp += amount;
		std::cout << "ClapTrap " << this->name << " has been repaired " << amount << " of HP." << std::endl;
		--this->ep;
	}
}
