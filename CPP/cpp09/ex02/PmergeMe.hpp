#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cstdlib>
#include <stdexcept>
#include <cctype>
#include <climits>
#include <ctime>

#include <algorithm>

class PmergeMe
{
private: // not using
	PmergeMe(PmergeMe& other);
	PmergeMe &operator=(PmergeMe& other);
	PmergeMe();
private:
	std::vector<uint> raw;
	std::vector<uint> vec;
	std::list<uint> list;

	void sort_vector();
	void sort_list();
public:
	PmergeMe(int ac, char **av);
	~PmergeMe();

	void run();
};

#endif
