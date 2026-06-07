#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::cout << "\n=== testing std::vector<int> ===" << std::endl;
	std::vector<int> v;
	for (int i = 0; i < 5; ++i)
		v.push_back(i * 2); // 0,2,4,6,8

	try {
		std::vector<int>::iterator it = easyfind(v, 4);
		std::cout << "Found in vector: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Vector error: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(v, 5);
		std::cout << "Found in vector: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Vector Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== testing std::list<int> ===" << std::endl;
	std::list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);

	try {
		std::list<int>::iterator it = easyfind(l, 20);
		std::cout << "Found in list: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "List error: " << e.what() << std::endl;
	}

	try {
		std::list<int>::iterator it = easyfind(l, 99);
		std::cout << "Found in list: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "List Error: " << e.what() << std::endl;
	}

	return 0;
}