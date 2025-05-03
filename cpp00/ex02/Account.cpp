#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:"
		<< _totalAmount << ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals << '\n';
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount << ";created" << '\n';
	_nbAccounts++;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount << ";closed" << '\n';
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount << ";deposits:"
		<< _nbDeposits << ";withdrawals:"
		<< _nbWithdrawals << '\n';
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << ++_nbDeposits << '\n';
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout << "refused" << '\n';
		return (false);
	}
	_amount -= withdrawal;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << ++_nbWithdrawals << '\n';
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}

void	Account::_displayTimestamp( void )
{
	time_t time = std::time(NULL);
	tm  *time_struct = localtime(&time);
	std::cout << '[' << 1900 + time_struct->tm_year
		<< std::setw(2) << std::setfill('0') << time_struct->tm_mon + 1
		<< std::setw(2) << std::setfill('0') << time_struct->tm_mday
		<< '_'
		<< std::setw(2) << std::setfill('0') << time_struct->tm_hour
		<< std::setw(2) << std::setfill('0') << time_struct->tm_min
		<< std::setw(2) << std::setfill('0') << time_struct->tm_sec
		<< ']';
}
