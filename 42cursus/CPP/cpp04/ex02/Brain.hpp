#ifndef BRAIN_HPP
#define BRAIN_HPP

#define IDEA_SIZE 100

#include <string>
#include <iostream>

class Brain
{
private:
	std::string ideas[IDEA_SIZE];
public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	void appendIdea(std::string idea);
	void shareIdea() const;
};

#endif