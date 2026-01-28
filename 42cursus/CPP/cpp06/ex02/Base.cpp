#include "Base.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base::~Base() {}

Base* generate(void)
{
	Base* base;
	std::srand(std::time(NULL));
	int random = std::rand() % 3;
	
	if (random == 0)
		base = new A();
	else if (random == 1)
		base = new B();
	else
		base = new C();
	return base;
}

void identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	if (a)
		std::cout << "actual type of the object pointed to by is A" << std::endl;
	B* b = dynamic_cast<B*>(p);
	if (b)
		std::cout << "actual type of the object pointed to by is B" << std::endl;
	C* c = dynamic_cast<C*>(p);
	if (c)
		std::cout << "actual type of the object pointed to by is C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "actual type of the object pointed to by is A" << std::endl;
	}
	catch(const std::exception& e) {}
	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout << "actual type of the object pointed to by is B" << std::endl;
	}
	catch(const std::exception& e) {}
	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout << "actual type of the object pointed to by is C" << std::endl;
	}
	catch(const std::exception& e) {}	
}
