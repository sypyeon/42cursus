#include "Zombie.hpp"

int main()
{
	Zombie *heap;

	heap = newZombie("heap");
	heap->announce();
	randomChump("stack");
	return 0;
}
