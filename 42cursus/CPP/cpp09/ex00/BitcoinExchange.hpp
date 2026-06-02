#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>

class BitcoinExchange
{
private:
	std::map<std::string, float> data;
	std::map<std::string, float> input;

	BitcoinExchange(BitcoinExchange& other);
	BitcoinExchange& operator=(BitcoinExchange& other);
public:
	BitcoinExchange();
	~BitcoinExchange();

	void processInput(std::string& file_name);
private:
	bool isValidDate(const std::string& date);
	bool isValidValue(const std::string& value);
};

#endif