#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "CALL: Brain default constructor." << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i].clear();
}

Brain::Brain(const Brain &other)
{
	std::cout << "CALL: Brain copy constructor." << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "CALL: Brain copy assignment operator." << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "CALL: Brain destructor." << std::endl;
}
