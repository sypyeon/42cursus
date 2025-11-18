#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap finn("Finn");

	finn.attack("enemy");
	finn.beRepaired(1);
	finn.takeDamage(11);
	finn.beRepaired(1);
	finn.attack("enemy");
	finn.attack("enemy");
	finn.highFivesGuys();
	finn.takeDamage(111);
	return 0;
}
