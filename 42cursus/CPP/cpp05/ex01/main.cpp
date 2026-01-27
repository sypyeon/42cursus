#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Create Bureaucrats ===" << std::endl;
	Bureaucrat lowGrade("LowGrade", 150);
	std::cout << lowGrade << std::endl;
	Bureaucrat highGrade("HighGrade", 1);
	std::cout << highGrade << std::endl << std::endl;

	//Form
	std::cout << "=== Create valid Forms ===" << std::endl;
	Form topSecret("Top secret", 1, 1);
	std::cout << topSecret << std::endl;
	Form commonForm("Common form", 150, 150);
	std::cout << commonForm << std::endl << std::endl;

	std::cout << "=== Create invalid Forms ===" << std::endl;
	try {Form invalidFormLow("invalid form low grade", 200, 200);}
	catch (const std::exception& e) {std::cerr << e.what() << std::endl;}
	try {Form invalidFormHigh("invalid form high grade", 0, 0);}
	catch (std::exception& e) {std::cerr << e.what() << std::endl;}

	std::cout << std::endl << "===== Sign Forms =====" << std::endl;
	try {lowGrade.signForm(topSecret);}
	catch (std::exception& e) {std::cerr << e.what() << std::endl;}
	try {lowGrade.signForm(commonForm);}
	catch (std::exception& e) {std::cerr << e.what() << std::endl;}
	try {highGrade.signForm(commonForm);}
	catch (std::exception& e) {std::cerr << e.what() << std::endl;}

	std::cout << std::endl << "===== Check Forms =====" << std::endl;
	std::cout << topSecret << std::endl;
	std::cout << commonForm << std::endl;
}