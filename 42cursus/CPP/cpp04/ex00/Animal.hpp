#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal &animal);
	Animal &operator=(const Animal &animal);
	~Animal();

	void makeSound() const;
	std::string getType() const;
};

#endif