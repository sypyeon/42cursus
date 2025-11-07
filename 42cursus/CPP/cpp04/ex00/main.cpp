#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void testPolymorphism()
{
	std::cout << "=== TESTING POLYMORPHISM WITH CORRECT CLASSES ===" << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << "\nTypes:" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	std::cout << "\nSounds (should be specific to each animal):" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound(); //will output the dog sound!
	meta->makeSound(); //will output generic animal sound!
	
	std::cout << "\nDestroying animals..." << std::endl;
	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;
}

void testWrongPolymorphism()
{
	std::cout << "=== TESTING NON-POLYMORPHISM WITH WRONG CLASSES ===" << std::endl;
	
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	
	std::cout << "\nTypes:" << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	
	std::cout << "\nSounds (WrongCat should output WrongAnimal sound due to no virtual!):" << std::endl;
	wrongCat->makeSound(); //will output the WrongAnimal sound, NOT WrongCat!
	wrongMeta->makeSound();
	
	std::cout << "\nDestroying wrong animals..." << std::endl;
	delete wrongMeta;
	delete wrongCat;
	std::cout << std::endl;
}

void testConstructorsDestructors()
{
	std::cout << "=== TESTING CONSTRUCTORS AND DESTRUCTORS ===" << std::endl;
	
	std::cout << "\nCreating Dog on stack:" << std::endl;
	Dog stackDog;
	std::cout << "Stack dog type: " << stackDog.getType() << std::endl;
	stackDog.makeSound();
	
	std::cout << "\nCreating Cat on stack:" << std::endl;
	Cat stackCat;
	std::cout << "Stack cat type: " << stackCat.getType() << std::endl;
	stackCat.makeSound();
	
	std::cout << "\nTesting copy constructor:" << std::endl;
	Dog copyDog(stackDog);
	std::cout << "Copy dog type: " << copyDog.getType() << std::endl;
	copyDog.makeSound();
	
	std::cout << "\nTesting assignment operator:" << std::endl;
	Cat assignCat;
	assignCat = stackCat;
	std::cout << "Assigned cat type: " << assignCat.getType() << std::endl;
	assignCat.makeSound();
	
	std::cout << "\nStack objects will be destroyed automatically..." << std::endl;
}

void testArrayOfAnimals()
{
	std::cout << "=== TESTING ARRAY OF ANIMALS ===" << std::endl;
	
	const int size = 4;
	Animal* animals[size];
	
	std::cout << "\nCreating array of animals:" << std::endl;
	animals[0] = new Animal();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Dog();
	
	std::cout << "\nTesting polymorphic behavior in array:" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << "Animal " << i << " type: " << animals[i]->getType() << " - ";
		animals[i]->makeSound();
	}
	
	std::cout << "\nDestroying array of animals:" << std::endl;
	for (int i = 0; i < size; i++)
	{
		delete animals[i];
	}
	std::cout << std::endl;
}

int main()
{
	testPolymorphism();
	testWrongPolymorphism();
	testConstructorsDestructors();
	testArrayOfAnimals();
	
	return 0;
}