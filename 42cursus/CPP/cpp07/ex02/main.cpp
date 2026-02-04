#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Array.hpp"

#define MAX_VAL 20
int main(int, char **)
{
	int *a = new int();
	Array<int> aa(-1);
	std::cout << "size of a:  " << *a << std::endl;
	std::cout << "size of aa: " << aa.size() << std::endl;
	delete a;

	std::cout << std::endl << "=== testing random values ===" << std::endl;
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
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cerr << "== array<int> and int* saved the same value ==" << std::endl;
	// SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	try { numbers[-2] = 0; }
	catch (const std::exception &e) { std::cerr << e.what() << std::endl; }
	try { numbers[MAX_VAL] = 0; }
	catch (const std::exception &e) { std::cerr << e.what() << std::endl; }

	delete[] mirror;
	return 0;
}