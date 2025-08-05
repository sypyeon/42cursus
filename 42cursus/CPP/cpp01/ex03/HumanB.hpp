#ifndef HUMANB_CPP
# define HUMANB_CPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
	private:
		std::string name;
		Weapon weapon;
	public:
		std::string getName() const;
		void setName(std::string name);
		void attack();
};

#endif