#include "Zombie.hpp"

int main()
{
	Zombie *heap;

	heap = zombieHorde(5, "heap");
	delete[] heap;
	return 0;
}
