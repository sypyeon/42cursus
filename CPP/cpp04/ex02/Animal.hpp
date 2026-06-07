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
	Animal(std::string type);
	Animal(const Animal &animal);
	Animal &operator=(const Animal &animal);
	virtual ~Animal();

	virtual void makeSound() const = 0;
	const std::string getType() const;
};

#endif