#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>

class PmergeMe
{
private: // not using
	PmergeMe(PmergeMe& other);
	PmergeMe &operator=(PmergeMe& other);
	PmergeMe();
private:
	std::vector<int> vec;
	std::list<int> list;

	void sort_vector();
	void sort_list();
public:
	PmergeMe(char **av);
	~PmergeMe();

	void run(char **av);
};

#endif