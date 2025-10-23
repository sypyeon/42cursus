#include "replacefile.hpp"

replaceFile::replaceFile(std::string name, std::string s1, std::string s2)
	: name(name), s1(s1), s2(s2)
{}

void replaceFile::replaceAndCreateFile()
{
	this->file.open(this->name.c_str());
	if (!this->file)
	{
		std::cerr << "Error opening file: " << this->name << std::endl;
		return;
	}

	std::string content;
	std::string line;
	while (std::getline(this->file, line))
	{
		content += line + "\n";
	}
	this->file.close();

	if (this->s1.empty())
	{
		std::cerr << "Error: The first string to replace cannot be empty." << std::endl;
		return;
	}
	if (this->s1 == this->s2)
	{
		std::cerr << "Error: The strings to replace cannot be the same." << std::endl;
		return;
	}
	if (content.empty())
	{
		std::cerr << "Error: The file is empty." << std::endl;
		return;
	}

	size_t pos = 0;
	while ((pos = content.find(this->s1, pos)) != std::string::npos)
	{
		content.replace(pos, this->s1.length(), this->s2);
		pos += this->s2.length();
	}
	std::ofstream outFile((this->name + ".replace").c_str());
	if (!outFile.is_open())
	{
		std::cerr << "Error: Could not open file " << this->name + ".replace" << " for writing." << std::endl;
		return;
	}
	outFile << content;
	outFile.close();
}

replaceFile::~replaceFile()
{
	if (file.is_open())
		file.close();
}
