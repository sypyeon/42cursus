#include "ClapTrap.hpp"

int main()
{
	ClapTrap bob("bob");

	bob.attack("jake");
	bob.takeDamage(1);
	bob.beRepaired(2);
}
