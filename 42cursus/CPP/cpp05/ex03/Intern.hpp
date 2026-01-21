#ifndef INTERN_HPP
#define INTERN_HPP

#include <ostream>
#include <iostream>
#include <string>
#include <vector>
#include <exception>

class AForm;
class Intern
{
private:
	std::vector<std::string> formats; 
public:
	Intern();
	Intern(Intern &other);
	~Intern();
	Intern& operator=(Intern &other);

	AForm* makeForm(const std::string name, const std::string target) const;
	
	class FormDoesNotExist : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Intern& b);

#endif
