#include "ScavTrap.hpp"

int main()
{
	ScavTrap steve("steve");

	steve.attack("bob");
	steve.beRepaired(12);
	steve.takeDamage(13);

	((ClapTrap)steve).attack("bob");
	steve.guardGate();
	return 0;
}
