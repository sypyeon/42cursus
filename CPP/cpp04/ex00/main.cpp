#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void testPolymorphism()
{
	std::cout << "=== TESTING CORRECT CLASSES ===" << std::endl;
	
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "\nTypes:" << std::endl;
	std::cout << animal->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	animal->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << "\nDestroying animals..." << std::endl;
	delete animal;
	delete dog;
	delete cat;
	std::cout << std::endl;
}

void testWrongPolymorphism()
{
	std::cout << "=== TESTING WRONG CLASSES ===" << std::endl;
	
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	
	std::cout << "\nTypes:" << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;

	wrongCat->makeSound(); //will output the WrongAnimal sound, NOT WrongCat!
	wrongAnimal->makeSound();
	
	std::cout << "\nDestroying wrong animals..." << std::endl;
	delete wrongAnimal;
	delete wrongCat;
	std::cout << std::endl;
}

int main()
{
	testPolymorphism();
	testWrongPolymorphism();
	return 0;
}