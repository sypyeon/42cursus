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
	std::cout << "CALL: ClapTrap " << name << " constructor." << std::endl;
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
	this->hp = other.hp;
	this->ep = other.ep;
	this->ad = other.ad;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "CALL: ClapTrap " << name << " destructor." << std::endl;
}

bool ClapTrap::isAlive()
{
	if (this->hp > 0)
		return true;
	std::cout << "ClapTrap " << this->name << " ran out of hit points..." << std::endl;
	return false;
}

bool ClapTrap::hasEp()
{
	if (this->ep > 0)
		return true;
	std::cout << "ClapTrap " << this->name << " ran out of energy points..." << std::endl;
	return false;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->isAlive() && this->hasEp())
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->ad << " points of damage!" << std::endl;
		--this->ep;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->isAlive())
	{
		std::cout << "ClapTrap " << this->name << " has taken " << amount << " damage!" << std::endl;
		if (amount >= static_cast<unsigned int>(this->hp))
		{
			this->hp = 0;
			std::cout << "ClapTrap " << this->name << " has been destroyed!" << std::endl;
		}
		else
			this->hp -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->isAlive() && this->hasEp())
	{
		this->hp += amount;
		std::cout << "ClapTrap " << this->name << " has been repaired " << amount << " of HP." << std::endl;
		--this->ep;
	}
}
