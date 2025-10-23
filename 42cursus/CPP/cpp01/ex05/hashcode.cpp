#include "Harl.hpp"

int hashcode(std::string str)
{
	int hash = 0;
	int i = 0;

	while (str[i])
	{
		hash += str[i];
		i++;
	}
	return hash % HARL_HASH;
}
