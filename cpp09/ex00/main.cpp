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

	if (mth == 1 || mth == 1 || mth == 1 || mth == 1 || mth == 1 || mth == 1 || mth == 1)
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

	int	yr = atoi(year.c_str());
	int	mth = atoi(month.c_str());
	int	dy = atoi(day.c_str());

	if (yr < 2009 || yr > 2025 || mth < 1 || mth > 12 || dy < 1 || dy > 31)
		throw error("Error: bad input => " + line);
	
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
	if (amount.find_first_not_of("0123456789.") != std::string::npos)
		throw error("Error: bad input => " + line);

	float	val = atof(amount.c_str());

	if (val < 0)
		throw error("Error: not a positive number => " + line);
	else if (val > 1000)
		throw error("Error: too large a number => " + line);
}



int	main(int ac, char** av)
{
	std::fstream		input(av[1]);
	std::fstream		dbase("data.csv");
	BitcoinExchange		data_base;
	std::string			line;

	try
	{
		if (ac != 2 || !input.is_open() || !input.is_open())
			throw error("Error: could not open file.");

		data_base.fill(dbase);
		while(std::getline(input, line))
		{
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
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}



// int	main(int ac, char** av)
// {
// 	std::fstream		input(av[1]);
// 	std::fstream		dbase("data.csv");
// 	BitcoinExchange		data_base;
// 	std::string			line;

// 	if (ac != 2 || !input.is_open() || !input.is_open())
// 	{
// 		std::cerr << "Error: could not open file." << std::endl;
// 		_exit(1);
// 	}

// 	data_base.fill(dbase);
// 	while(std::getline(input, line))
// 	{
// 		std::string	date;
// 		std::string	value;
// 		size_t		pos;
// 		pos = line.find('|');
// 		if (pos == std::string::npos)
// 		{
// 			std::cout << "Error: bad input => " << line << std::endl;
// 			continue ;
// 		}
// 		date = line.substr(0, pos - 1);
// 		value = line.substr(pos + 2);
// 		try
// 		{
// 			std::stringstream ss_date(date);
// 			std::stringstream ss_value(value);
// 			parse_date(ss_date, line);
// 			parse_value(ss_value, line);
// 			std::cout << date << " => " << value << " = " << data_base.calcul_price(date, value) << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << '\n';
// 		}
// 	}
// 	return 0;
// }
