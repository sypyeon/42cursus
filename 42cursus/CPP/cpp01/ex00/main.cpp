#include "Zombie.hpp"

int main()
{
	Zombie *heap;

	heap = newZombie("heap");
	heap->announce();
	randomChump("stack");

	std::cout << "Stack zombie is destroyed when function ends" << std::endl;
	std::cout << heap->get_name() << " zombie is destroyed" << std::endl;
	delete heap;
	return 0;
}
