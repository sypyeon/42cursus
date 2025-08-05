#include "Zombie.hpp"

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::get_name() const
{
	return this->name;
}
