#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <fstream>
#include <string>
#include <stdlib.h>

class error: public std::exception
{
	private:
		std::string str;
	public:
		error(std::string err): str(err) {};
		~error() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {};
		virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {return str.c_str();};
};

class BitcoinExchange
{
private:
	std::map<std::string , float> data;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator= (const BitcoinExchange& other);
	~BitcoinExchange();

	void		fill(std::fstream& file);
	float		calcul_price(std::string date, std::string value);
	std::string	find_the_closest_date(std::string date);
};

#endif
