#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
	std::cout << "CALL: FragTrap default constructor." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
	std::cout << "FragTrap " << name << " constructor." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
	
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{

}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " has been destroyed." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " requests a positive high-five!" << std::endl;
}
