#include "HumanA.hpp"

std::string HumanA::getName() const { return this->name; }

void HumanA::setName(std::string name) { this->name = name; }

void HumanA::attack() { std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl; }

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}
