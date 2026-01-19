#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Create valid Bureaucrats ===" << std::endl;
	Bureaucrat lowGrade("LowGrade", 150);
	std::cout << lowGrade << std::endl;
	Bureaucrat highGrade("HighGrade", 1);
	std::cout << highGrade << std::endl << std::endl;

	std::cout << "=== Create invalid Bureaucrats ===" << std::endl;
	try {Bureaucrat tooLow("tooLow", 151);}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	try {Bureaucrat tooHigh("tooHigh", 0);}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	std::cout << std::endl;

	//invalid decrement
	std::cout << "Trying to decrease grade of " << lowGrade << std::endl;
	try	{lowGrade.decrementGrade();}
	catch(const std::exception& e) {std::cerr << e.what() << '\n';}
	std::cout << "Trying to increase grade of " << lowGrade << std::endl;
	try	{lowGrade.incrementGrade();}
	catch(const std::exception& e) {std::cerr << e.what() << '\n';}
	std::cout << std::endl;

	//invalid increment
	std::cout << "Trying to increase grade of " << highGrade << std::endl;
	try	{highGrade.incrementGrade();}
	catch(const std::exception& e) {std::cerr << e.what() << '\n';}
	//valid decrement
	std::cout << "Trying to decrease grade of " << highGrade << std::endl;
	try	{highGrade.decrementGrade();}
	catch(const std::exception& e) {std::cerr << e.what() << '\n';}
	std::cout << std::endl;
	std::cout << std::endl;


	//Form
	std::cout << "=== Create valid Forms ===" << std::endl;
	Form topSecret("Top secret", 1, 1);
	try {Form topSecret("Top secret", 1, 1);}
	catch(const std::exception& e) {std::cerr << e.what() << std::endl;}
	std::cout << topSecret << std::endl;
	Form commonForm("Common form", 150, 150);
	std::cout << commonForm << std::endl << std::endl;
	std::cout << "=== Create invalid Forms ===" << std::endl;
	try {Form invalidFormLow("invalid form low grade", 200, 200);}
	catch (const std::exception& e) {std::cerr << e.what() << std::endl;}
	try {Form invalidFormHigh("invalid form high grade", 0, 0);}
	catch (std::exception& e) {std::cerr << e.what() << std::endl << std::endl;}

	std::cout << "===== Sign Forms =====" << std::endl;
	try {lowGrade.signForm(topSecret);}
	catch (std::exception& e) {std::cerr << e.what() << std::endl;}
	try {highGrade.signForm(topSecret);}
	catch (std::exception& e) {std::cerr << e.what() << std::endl;}
}