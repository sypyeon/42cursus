#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>

PhoneBook::PhoneBook() : noc(0), curr(0)
{
	std::cout << "ADD: save a new contact" << std::endl;
	std::cout << "SEARCH: display a specific contact" << std::endl;
	std::cout << "EXIT: quit program. contacts are lost forever!" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Bye!" << std::endl;
}

void PhoneBook::add_contact()
{
	contact[curr].input_contact();
	curr++;
	if (noc < 8)
		noc++;
	if (curr >= 8)
		curr = 0;
}

void display_search_header()
{
	std::cout << "=============================================" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "=============================================" << std::endl;
}

void PhoneBook::search_phonebook()
{
	int i = 0;
	std::string input;

	display_search_header();
	if (noc == 0)
	{
		std::cout << "No contacts available." << std::endl;
		return;
	}
	while (noc > i)
	{
		contact[i].display_search(i);
		i++;
	}
	std::cout << "Index of contact to display: ";
	std::getline(std::cin, input);
	std::stringstream ss(input);
	int index;
	if ((ss >> index) && (index >= 1 && index <= 8) && index <= noc)
		contact[index - 1].display_contact();
	else
		std::cout << "Invalid index!" << std::endl;
}
