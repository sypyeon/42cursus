#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>

class From
{
private:
	const std::string name;
	bool isSigned;
	const int toSign;
	const int toExec;
public:
	Form();
	Form();
	Form(Form& other);
	~Form();

	std::string getName();
	bool getIsSigned();
	int getToSign();
	int getToExec();

	class GradeTooHighException: public std::exception
	{
		virtual const char* what() const throw();
	};
};

#endif