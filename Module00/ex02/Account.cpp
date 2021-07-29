#include "Account.hpp"
#include <iostream>
#include <ctime>

static void	put_nbr(int nbr) {

	if (nbr > 9)
		std::cout << nbr;
	else
		std::cout << '0' << nbr;
}

void	Account::_displayTimestamp( void ) {

	std::time_t	now = std::time(0);
	std::tm		*nnow = std::localtime(&now);

	std::cout << "[" << nnow->tm_year + 1900;
	put_nbr(nnow->tm_mon + 1);
	put_nbr(nnow->tm_mday);
	std::cout << '_';
	put_nbr(nnow->tm_hour);
	put_nbr(nnow->tm_min);
	put_nbr(nnow->tm_sec);
	std::cout << "]";
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {

	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ) {

	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {

	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts() << ';'
			  << "total:" << Account::getTotalAmount() << ';'
			  << "deposits:" << Account::getNbDeposits() << ';'
			  << "withdrawals:" << Account::getNbWithdrawals() << '\n';
}

Account::Account( int initial_deposit ) {

	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ';'
			  << "amount:" << this->_amount << ";created\n";
}

Account::~Account( void ) {

	Account::_nbAccounts -= 1;
	Account::_totalAmount -= this->_amount;
	Account::_totalNbDeposits -= this->_nbDeposits;
	Account::_totalNbWithdrawals -= this->_nbWithdrawals;

	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ';'
			  << "amount:" << this->_amount << ";closed\n";
}

void	Account::displayStatus( void ) const {

	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ';'
			  << "amount:" << this->_amount << ';'
			  << "deposits:" << this->_nbDeposits << ';'
			  << "withdrawals:" << this->_nbWithdrawals << '\n';
}

void	Account::makeDeposit( int deposit ) {

	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ';'
			  << "p_amount:" << this->_amount << ';'
			  << "deposit:" << deposit << ';'
			  << "amount:" << deposit + this->_amount << ';'
			  << "nb_deposits:" << this->_nbDeposits + 1 << '\n';

	this->_nbDeposits += 1;
	this->_amount += deposit;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
}

int	Account::checkAmount( void ) const {

	return (this->_amount);
}

bool	Account::makeWithdrawal( int withdrawal ) {

	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ';'
			  << "p_amount:" << this->_amount << ';';
	if (this->checkAmount() < withdrawal) {
		std::cout << "withdrawal:refused\n";
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal << ';'
			  << "amount:" << this->_amount - withdrawal << ';'
			  << "nb_withdrawals:" << this->_nbWithdrawals + 1 << '\n';

	this->_nbWithdrawals += 1;
	this->_amount -= withdrawal;

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;
	return (true);
}
