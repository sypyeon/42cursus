#include "Serializer.hpp"

#include <iostream>

int main()
{
	Data data;

	data.value = 42;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << raw << std::endl;
	data = *(Serializer::deserialize(raw));
	std::cout << data.value << std::endl;
	return 0;
}