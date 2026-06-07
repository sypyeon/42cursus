#ifndef HUMANA_CPP
#define HUMANA_CPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
private:
	std::string name;
	Weapon &weapon;

public:
	HumanA(std::string name, Weapon &weapon);
	std::string getName() const;
	void setName(std::string name);
	void attack();
};

#endif