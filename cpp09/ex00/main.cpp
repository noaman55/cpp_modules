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

void	parse_date(std::stringstream date, std::string& line)
{
	std::string	year;
	std::string	month;
	std::string	day;

	std::getline(date, year, '-');
	std::getline(date, month, '-');
	std::getline(date, day, '-');

	if (year.empty() || month.empty() || day.empty())
		throw error("Error: bad input => " + line);
	if (is_digits(year) || is_digits(month) || is_digits(day))
		throw error("Error: bad input => " + line);

	int	yr = atoi(year.c_str());
	int	mth = atoi(month.c_str());
	int	dy = atoi(day.c_str());

	if (yr < 2009 || yr > 2025 || mth < 1 || mth > 12 || dy < 1 || dy > 31)
		throw error("Error: bad input => " + line);
}

int	main(int ac, char** av)
{
	std::fstream		input(av[1]);
	std::fstream		dbase("data.csv");
	BitcoinExchange		data_base;
	std::string			line;

	if (ac != 2 || !input.is_open() || !input.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		_exit(1);
	}

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
			parse_date(date, line);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << date << " => " << value << " = " << data_base.calcul_price(date, value) << std::endl;
	}

	return 0;
}
