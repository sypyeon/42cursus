#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "Error: Nothing to sort." << std::endl;
		return 1;
	}

	try {
		PmergeMe pm(ac, av);
		pm.run();
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
