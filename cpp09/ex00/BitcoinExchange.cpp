#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->data = other.data;
};

BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& other)
{
	if (this != &other)
		this->data = other.data;
	return *this;
};

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::fill(std::fstream& file)
{
	std::string	line;

	while(std::getline(file, line))
	{
		if (line == "date,exchange_rate")
			continue;
		std::string date;
		std::string exchange_rate;
		size_t		pos;
		pos = line.find(',');
		date = line.substr(0, pos);
		exchange_rate = line.substr(pos + 1);
		data[date] = atof(exchange_rate.c_str());
	}
}

std::string	BitcoinExchange::find_the_closest_date(std::string date)
{
	std::map<std::string, float>::iterator it;
	std::string closest_date;

	it = data.begin();
	while (it != data.end())
	{
		if (it->first <= date)
			closest_date = it->first;
		++it;
	}
	return closest_date;
}

float	BitcoinExchange::calcul_price(std::string date, std::string value)
{
	std::map<std::string, float>::iterator it;

	it  = data.find(date);
	if (it != data.end())
		return it->second * atof(value.c_str());
	else
	{
		std::string closest_date = find_the_closest_date(date);
		if (closest_date.empty())
			return -9;
		else
			return data.at(closest_date) * atof(value.c_str());
	}
}
