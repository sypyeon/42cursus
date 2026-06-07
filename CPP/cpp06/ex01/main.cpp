#include "Serializer.hpp"

#include <iostream>

int main()
{
	Data data;

	data.value = 42;
	std::cout << "data value: " << data.value << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "serialized value:   " << raw << std::endl;
	data = *(Serializer::deserialize(raw));
	std::cout << "deserialized value: " << data.value << std::endl;
}