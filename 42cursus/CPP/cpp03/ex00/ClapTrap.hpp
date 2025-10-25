#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
private:
	std::string name;
	int hp;
	int ep;
	int ad;
public:
	ClapTrap(std::string name);
	~ClapTrap();
};

ClapTrap::ClapTrap(/* args */)
{
}

ClapTrap::~ClapTrap()
{
}


#endif