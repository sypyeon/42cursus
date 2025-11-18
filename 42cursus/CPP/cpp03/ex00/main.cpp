#include "ClapTrap.hpp"

int main()
{
	ClapTrap bob("bob");
	ClapTrap jake("jake");
	ClapTrap bob2(bob);
	bob = jake;

	jake.takeDamage(50);
	jake.attack("enemy");
	bob2.takeDamage(1);
	bob.beRepaired(2);
	bob.attack("enemy");
	bob.attack("enemy");
	bob.attack("enemy");
	bob.attack("enemy");
	bob.attack("enemy");
	bob.attack("enemy");
	bob.attack("enemy");
	bob.attack("enemy");
	bob.attack("enemy");
	bob.attack("enemy");
	bob.beRepaired(2);
	bob.takeDamage(12);
}
