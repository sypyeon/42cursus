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
	AForm* (Intern::*formatCreateFunction[3])(std::string target);
	AForm* robotomyForm(std::string target);
	AForm* presidentialForm(std::string target);
	AForm* shrubberyForm(std::string target);
	Intern(Intern &other);
	Intern& operator=(Intern &other);
public:
	Intern();
	~Intern();

	AForm* makeForm(const std::string name, const std::string target);
	
	class FormDoesNotExist : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Intern& b);

#endif
