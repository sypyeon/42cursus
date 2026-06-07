#include "Zombie.hpp"

std::string InToString(int num)
{
    std::stringstream ss;
    ss << num;
    return ss.str();
}

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombie;

	zombie = new Zombie[N];
	for(int i = 0; i < N; i++)
	{
		zombie[i].setName(name);
		zombie[i].announce();
	}
	return (zombie);
}
