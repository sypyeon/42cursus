#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	Bureaucrat lowGrade("LowGrade", 150);
	std::cout << lowGrade << std::endl;
	Bureaucrat highGrade("HighGrade", 1);
	std::cout << highGrade << std::endl;

	std::cout << "Trying to construct Bureaucrat with too low grade." << std::endl;
	try {Bureaucrat tooLow("tooLow", 151);}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	std::cout << std::endl;

	//invalid decrement
	std::cout << "Trying to decrease grade of " << lowGrade << std::endl;
	try	{lowGrade.decrementGrade();}
	catch(const std::exception& e) {std::cerr << e.what() << '\n';}
	std::cout << std::endl;

	//valid increment
	std::cout << "Trying to increase grade of " << lowGrade << std::endl;
	try	{lowGrade.incrementGrade();}
	catch(const std::exception& e) {std::cerr << e.what() << '\n';}
	std::cout << std::endl;

	//invalid increment
	std::cout << "Trying to increase grade of " << highGrade << std::endl;
	try	{highGrade.incrementGrade();}
	catch(const std::exception& e) {std::cerr << e.what() << '\n';}
	std::cout << std::endl;

	//valid decrement
	std::cout << "Trying to decrease grade of " << highGrade << std::endl;
	try	{highGrade.decrementGrade();}
	catch(const std::exception& e) {std::cerr << e.what() << '\n';}
	std::cout << std::endl;


	//Form
	Form topSecret("Top secret", 1, 1);
	Form commonForm("Common form", 150, 150);
	Form invaldForm("invalid form", 200, 200);
}