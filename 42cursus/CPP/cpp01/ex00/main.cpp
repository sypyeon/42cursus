#include "Zombie.hpp"

int main()
{
	Zombie *heap;

	randomChump("stack zombie");
	heap = newZombie("heap zombie");
	heap->announce();

	delete heap;
	return 0;
}
