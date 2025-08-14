#include "replacefile.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: " << av[0] << " <string>" << std::endl;
		return 1;
	}
	replaceFile file(av[1], av[2], av[3]);
	file.replaceAndCreateFile();
	return 0;
} 
