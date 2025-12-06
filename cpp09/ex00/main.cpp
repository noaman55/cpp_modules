#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sstream>

bool is_digits(std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

bool	leap_year(int year)
{
	if (year % 400 == 0)
		return true;
	else if (year % 100 == 0)
		return false;
	else if (year % 4 == 0)
		return true;
	else
		return false;
}

void	is_date_valid(int year, int mth, int day, std::string& line)
{
	int max_day;

	if (mth == 1 || mth == 3 || mth == 5 || mth == 7 || mth == 8 || mth == 10 || mth == 12)
		max_day = 31;
	else if (mth == 2 && leap_year(year))
		max_day = 29;
	else if (mth == 2 && !leap_year(year))
		max_day = 28;
	else
		max_day = 30;

	if (day < 1 || day > max_day)
		throw error("Error: bad input => invalid date " + line);
}

void	parse_date(std::stringstream& date, std::string& line)
{
	std::string	year;
	std::string	month;
	std::string	day;

	std::getline(date, year, '-');
	std::getline(date, month, '-');
	std::getline(date, day, '-');

	if (year.empty() || month.empty() || day.empty())
		throw error("Error: bad input => " + line);
	if (!is_digits(year) || !is_digits(month) || !is_digits(day))
		throw error("Error: bad input => " + line);
	if (month.size() != 2 || day.size() != 2)
		throw error("Error: bad input => month or day must be in the format of two digits " + line);
	

	int	yr = atoi(year.c_str());
	int	mth = atoi(month.c_str());
	int	dy = atoi(day.c_str());

	if (yr < 2009 || yr > 2025 || mth < 1 || mth > 12 || dy < 1 || dy > 31)
		throw error("Error: invalid date => " + line);
	
	is_date_valid(yr, mth, dy, line);
}

void	parse_value(std::stringstream& value, std::string& line)
{
	std::string	amount;
	std::string	str; // for an extra string after the value

	std::getline(value, amount, ' ');
	std::getline(value, str, ' ');

	if (amount.empty() || !str.empty())
		throw error("Error: bad input => " + line);
	if (amount.find_first_not_of("0123456789.-") != std::string::npos)
		throw error("Error: bad input => " + line);

	float	val = atof(amount.c_str());

	if (val < 0)
		throw error("Error: not a positive number => " + line);
	else if (val > 1000)
		throw error("Error: too large a number => " + line);
}

void	parse_input(std::fstream& input, BitcoinExchange& data_base)
{
	std::string			line;

	while(std::getline(input, line))
	{
		if (line == "date | value")
			continue;
		std::string	date;
		std::string	value;
		size_t		pos;
		pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		date = line.substr(0, pos - 1);
		value = line.substr(pos + 2);
		try
		{
			std::stringstream ss_date(date);
			std::stringstream ss_value(value);
			parse_date(ss_date, line);
			parse_value(ss_value, line);
			std::cout << date << " => " << value << " = " << data_base.calcul_price(date, value) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

template <typename T>
T max (T a, T b)
{
	return a > b ? a : b;
}

int	main(int ac, char** av)
{
	std::fstream		input(av[1]);
	std::fstream		dbase("data.csv");
	BitcoinExchange		data_base;
	std::string			line;

	max<int> (5, 3);
	max<double> (5.1, 6.2);
	try
	{
		if (ac != 2 || !input.is_open() || !input.is_open())
			throw error("Error: could not open file.");

		data_base.fill(dbase);
		parse_input(input, data_base);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}

