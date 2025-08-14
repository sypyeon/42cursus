#ifndef REPLACEFILE_HPP
#define REPLACEFILE_HPP

#include <string>
#include <fstream>
#include <iostream>

class replaceFile
{
private:
	std::string name;
	std::string s1;
	std::string s2;
	std::ifstream file;
public:
	replaceFile(std::string name, std::string s1, std::string s2);
	void replaceAndCreateFile();
	~replaceFile();
};

#endif
