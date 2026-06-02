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
	std::ifstream fs("data.csv");
	if (!fs.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}

	std::string line;
	std::getline(fs, line);
	if(line != "date,exchange_rate")
		return ;

	while (std::getline(fs, line))
	{
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;
		std::string date = line.substr(0, commaPos);
		std::string rateStr = line.substr(commaPos + 1);
		double rate = std::atof(rateStr.c_str());
		this->data[date] = static_cast<float>(rate);
	}
	fs.close();
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10) return false;
	if (date[4] != '-' || date[7] != '-') return false;
	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7) continue;
		if (!std::isdigit(date[i])) return false;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12) return false;
	if (day < 1 || day > 31) return false;

	// Simple leap year check for Feb
	if (month == 2) {
		bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (day > (isLeap ? 29 : 28)) return false;
	}
	// Months with 30 days
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30) return false;
	}

	return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr)
{
	if (valueStr.empty()) return false;
	char* endptr;
	double val = std::strtod(valueStr.c_str(), &endptr);
	if (*endptr != '\0') return false;
	if (val < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (val > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::processInput(std::string& file_name)
{
	std::ifstream fs(file_name.c_str());
	if (!fs.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(fs, line); // Skip header

	while (std::getline(fs, line))
	{
		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pipePos);
		// Trim spaces
		date.erase(date.find_last_not_of(" ") + 1);
		
		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		std::string valueStr = line.substr(pipePos + 1);
		// Trim spaces
		size_t first = valueStr.find_first_not_of(" ");
		if (first != std::string::npos)
			valueStr = valueStr.substr(first);
		size_t last = valueStr.find_last_not_of(" ");
		if (last != std::string::npos)
			valueStr = valueStr.substr(0, last + 1);

		char* endptr;
		double val = std::strtod(valueStr.c_str(), &endptr);
		if (*endptr != '\0' || valueStr.empty()) {
			std::cerr << "Error: bad input => " << valueStr << std::endl;
			continue;
		}

		if (val < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (val > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, float>::iterator it = this->data.lower_bound(date);
		if (it == this->data.end() || it->first != date) {
			if (it == this->data.begin()) {
				// No date before or equal exists
				std::cerr << "Error: no data for date " << date << std::endl;
				continue;
			}
			--it;
		}
		
		std::cout << date << " => " << val << " = " << (val * it->second) << std::endl;
	}
	fs.close();
}
