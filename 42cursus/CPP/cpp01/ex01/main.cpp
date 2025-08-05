#include "Zombie.hpp"

int main()
{
	Zombie *heap;

	heap = zombieHorde(5, "heap");

	std::cout << heap->get_name() << " zombie horde is destroyed" << std::endl;
	delete[] heap;
	return 0;
}
