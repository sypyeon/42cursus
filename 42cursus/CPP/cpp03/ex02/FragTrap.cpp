#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
	std::cout << "FragTrap " << name << " has been created." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " has been destroyed." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " requests a positive high-five!" << std::endl;
}
