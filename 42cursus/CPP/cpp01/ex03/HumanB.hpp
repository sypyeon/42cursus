#ifndef HUMANB_CPP
# define HUMANB_CPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
	private:
		std::string name;
		Weapon* weapon;
	public:
		HumanB();
		HumanB(std::string name);
		std::string getName() const;
		void setName(std::string name);
		void setWeapon(Weapon& weapon);
		void attack();
};

#endif
