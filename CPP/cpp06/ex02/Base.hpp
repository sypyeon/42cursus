#ifndef BASE_HPP
#define BASE_HPP

class Base
{
public:
	virtual ~Base();
};

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif