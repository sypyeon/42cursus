#include "HumanB.hpp"

std::string HumanB::getName() const { return this->name; }

void HumanB::setName(std::string name) { this->name = name; }

void HumanB::setWeapon(Weapon& weapon) { this->weapon = &weapon; }

void HumanB::attack() { std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl; }

HumanB::HumanB() { this->name = "HumanB"; }

HumanB::HumanB(std::string name) { this->name = name; }
