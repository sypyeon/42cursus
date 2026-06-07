#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <stdexcept>
#include <cctype>
#include <climits>

#include <algorithm>

class PmergeMe
{
private: // not using
	PmergeMe(PmergeMe& other);
	PmergeMe &operator=(PmergeMe& other);
	PmergeMe();
private:
	std::vector<unsigned int> jacobsthal;
	std::vector<unsigned int> raw;
	std::vector<unsigned int> vec;
	std::deque<unsigned int> deq;

	void sort_vector();
	void sort_deque();
public:
	PmergeMe(int ac, char **av);
	~PmergeMe();

	void run();
};

#endif