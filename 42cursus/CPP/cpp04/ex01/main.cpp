#include "Cat.hpp"
#include "Dog.hpp"

#define ANIMAL_COUNT 10

// std::cout << "==================================" << std::endl << std::endl;
int main()
{
	Animal *animals[ANIMAL_COUNT];

	for (int i = 0; i < ANIMAL_COUNT; i++)
	{
		if (i < ANIMAL_COUNT/2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	Dog *dog = dynamic_cast<Dog*>(animals[0]);
	dog->getBrain()->appendIdea("Walk");
	dog->getBrain()->appendIdea("Play");
	
	Dog *otherDog = new Dog(*dog);
	otherDog->getBrain()->appendIdea("Treat");
	
	std::cout << std::endl << "===== Original Dog's ideas =====" << std::endl;
	dog->getBrain()->shareIdea();
	
	std::cout << std::endl << "===== Copied Dog's ideas =======" << std::endl;
	otherDog->getBrain()->shareIdea();
	
	delete otherDog;
	
	std::cout << std::endl << "===== Deleting all animals =====" << std::endl;
	for (int i = 0; i < ANIMAL_COUNT; i++)
		delete animals[i];

	return 0;
}