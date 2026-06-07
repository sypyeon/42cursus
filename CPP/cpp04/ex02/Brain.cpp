#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "CALL: Brain default constructor." << std::endl;
	for (int i = 0; i < IDEA_SIZE; i++)
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
		for (int i = 0; i < IDEA_SIZE; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "CALL: Brain destructor." << std::endl;
}

void Brain::appendIdea(std::string idea)
{
	for (int i = 0; i < IDEA_SIZE; i++)
	{
		if (this->ideas[i].empty())
		{
			this->ideas[i] = idea;
			break;
		}
	}
}

void Brain::shareIdea() const
{
	for (int i = 0; i < IDEA_SIZE && !this->ideas[i].empty(); i++)
		std::cout << "is thinking " << this->ideas[i] << std::endl;
}
