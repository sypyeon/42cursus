#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Array.hpp"

#define MAX_VAL 20
int main(int, char **)
{
	int *a = new int();
	Array<int> aa;
	std::cout << "=== testing default constructor ===" << std::endl;
	std::cout << "size of a:  " << *a << std::endl;
	std::cout << "=== construct with negative value ===" << std::endl;
	std::cout << "(underflow expected due to unsigned value)" << std::endl;
	std::cout << "size of aa: " << aa.size() << std::endl;
	delete a;

	std::cout << "\n=== testing random values ===" << std::endl;
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
		std::cout << numbers[i] << std::endl;
	}

	std::cout << "\n=== comparing random values ===" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cerr << "\n=== testing copy constructor and operator ===" << std::endl;
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	std::cerr << "\n=== testing exception handling test ===" << std::endl;
	try { numbers[-2] = 0; }
	catch (const std::exception &e) { std::cerr << e.what() << std::endl; }
	try { numbers[MAX_VAL] = 0; }
	catch (const std::exception &e) { std::cerr << e.what() << std::endl; }

	delete[] mirror;
	return 0;
}