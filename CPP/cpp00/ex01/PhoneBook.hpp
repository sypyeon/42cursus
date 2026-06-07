#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	int noc;
	int curr;
	Contact contact[8];

public:
	PhoneBook();
	~PhoneBook();
	void add_contact();
	void search_phonebook();
};

#endif
