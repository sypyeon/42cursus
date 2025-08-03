#include <string>
#include <iostream>
#include <sstream>

class Contact
{
	private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string phone_number;
	std::string darkest_secret;
	public:
	void display_contact();
	void display_search(int i);
    void input_contact();
};

class PhoneBook
{
	private:
	int		noc;
	Contact contact[8];
	public:
	PhoneBook() : noc(0) {}
	void add_contact();
	void search_phonebook();
};

void Contact::input_contact()
{
    std::cout << "First Name: ";
    std::cin >> first_name;
    std::cout << "Last Name: ";
    std::cin >> last_name;
    std::cout << "Nickname: ";
    std::cin >> nickname;
    std::cout << "Phone Number: ";
    std::cin >> phone_number;
    std::cout << "Darkest Secret: ";
    std::cin >> darkest_secret;
}

void PhoneBook::add_contact()
{
    contact[noc].input_contact();
    noc++;
    if (noc >= 8)
        noc = 0;
}

void Contact::display_contact()
{
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}

void	display_(std::string str)
{
	size_t i = 0;

	if (str.length() > 10)
	{
		str.erase(str.begin() + 9, str.end());
		str.push_back('.');
	}
	while (i < 10 - str.length())
	{
		std::cout << ' ';
		i++;
	}
	i = 0;
	while (i < str.length())
	{
		std::cout << str[i];
		i++;
	}
}

void	display_search_header()
{
	std::cout << "=============================================" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "=============================================" << std::endl;
}

void	Contact::display_search(int index)
{
	std::cout << '|';
	display_(std::to_string(index + 1));
	std::cout << '|';
	display_(first_name);
	std::cout << '|';
	display_(last_name);
	std::cout << '|';
	display_(nickname);
	std::cout << '|' << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

void	PhoneBook::search_phonebook()
{
	int i = 0;
	std::string input;

	display_search_header();
	while (noc > i)
	{
		contact[i].display_search(i);
		i++;
	}
	std::cout << "Index of contact to display: ";
	std::cin >> input;
	std::stringstream ss(input);
	int index;
	if ((ss >> index) && (index >= 1 && index <= 8) && index <= noc)
		contact[index - 1].display_contact();
	else
  	  std::cout << "Invalid index!" << std::endl;
}

int	main()
{
	PhoneBook phonebook;
	std::string input;

	while(true)
	{
		std::cout << std::endl << "Input command." << std::endl;
		std::cout << "ADD: save a new contact" << std::endl;
		std::cout << "SEARCH: display a specific contact" << std::endl;
		std::cout << "EXIT: quit program. contacts are lost forever!" << std::endl;
		std::cout << ">";
		std::cin >> input;
		if (input == "ADD" || input == "add")
			phonebook.add_contact();
		else if (input == "SEARCH" || input == "search")
			phonebook.search_phonebook();
		else if (input == "EXIT" || input == "exit")
			break;
	}
	return 0;
}
