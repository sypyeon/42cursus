#include "PmergeMe.hpp"

PmergeMe::PmergeMe(PmergeMe& other) { (void)other; }
PmergeMe &PmergeMe::operator=(PmergeMe& other) { (void)other; return *this;}
PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

static std::vector<unsigned int> gen_jacobsthal(int n)
{
	std::vector<unsigned int> jacobsthal;
	unsigned int limit = n / 2 + 1;

	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	unsigned int j = 1;
	while (jacobsthal.back() < limit)
	{
		int i = jacobsthal.size();
		j = jacobsthal.at(i - 1) + (2 * jacobsthal.at(i - 2));
		jacobsthal.push_back(j);
	}
	return jacobsthal;
}

PmergeMe::PmergeMe(int ac, char **av)
{
	(void)av;
	this->jacobsthal = gen_jacobsthal(ac);
	this->raw = 
}

void PmergeMe::sort_vector()
{

}

void PmergeMe::sort_list()
{

}

void PmergeMe::run()
{
	
}
