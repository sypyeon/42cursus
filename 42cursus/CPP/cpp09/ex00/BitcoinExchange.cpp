#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(BitcoinExchange& other)
{
	if (this != &other)
		*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange& other)
{
	if (this != &other)
	{
		this->data = other.data;
		this->input = other.input;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange()
{
	std::fstream fs("data.csv");

	while (fs.end())
}


void processInput(std::string& file_name)
{

}
