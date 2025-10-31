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
	std::string read_file();
	std::string replaced(std::string content) const;
	void create_file(std::string content) const;
	bool err_handle(std::string content) const;

public:
	replaceFile(std::string name, std::string s1, std::string s2);
	~replaceFile();
	void replaceAndCreateFile();
};

#endif
