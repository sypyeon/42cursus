#include "ClapTrap.hpp"

int main()
{
	ClapTrap bob("bob");
	ClapTrap jake("jake");
	ClapTrap bob2(bob);
	bob = jake;

	jake.takeDamage(50);
	bob2.takeDamage(1);
	bob.attack("jake");
	bob.takeDamage(1);
	bob.beRepaired(2);
}
