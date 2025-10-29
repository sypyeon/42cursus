#include "Contact.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

void	display_(std::string str)
{
	if (str.length() > 10)
	{
		str.erase(str.begin() + 9, str.end());
		str.push_back('.');
	}
	std::cout << std::setw(10);
	std::cout << str;
}

std::string int_to_string(int num)
{
    std::stringstream ss;
    ss << num;
    return ss.str();
}

void	Contact::display_search(int index) const
{
	std::cout << '|';
	display_(int_to_string(index + 1));
	std::cout << '|';
	display_(first_name);
	std::cout << '|';
	display_(last_name);
	std::cout << '|';
	display_(nickname);
	std::cout << '|' << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

void Contact::clear_contact()
{
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	darkest_secret = "";
}

void Contact::input_contact()
{
	this->clear_contact();
	while (first_name.empty())
	{
		std::cout << "First Name: ";
		std::getline(std::cin, first_name);
		if (!std::cin)
			return;
	}
	while (last_name.empty())
	{
		std::cout << "Last Name: ";
		std::getline(std::cin, last_name);
		if (!std::cin)
			return;
	}
	while (nickname.empty())
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, nickname);
		if (!std::cin)
			return;
	}
	while (phone_number.empty())
	{
		std::cout << "Phone Number: ";
		std::getline(std::cin, phone_number);
		if (!std::cin)
			return;
	}
	while (darkest_secret.empty())
	{
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, darkest_secret);
		if (!std::cin)
			return;
	}
}

void Contact::display_contact() const
{
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}
