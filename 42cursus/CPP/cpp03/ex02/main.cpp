#include "FragTrap.hpp"

int main()
{
	FragTrap frank("Frank");
	
	frank.attack("target");
	frank.beRepaired(50);
	frank.takeDamage(20);
	frank.highFivesGuys();
	return 0;
}
