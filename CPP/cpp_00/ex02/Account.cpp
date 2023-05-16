/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:01:48 by marco             #+#    #+#             */
/*   Updated: 2023/05/16 21:42:37 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _displayTimestamp();
    _totalAmount += initial_deposit;
	_accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::Account( void )
{
    _displayTimestamp();
	_accountIndex = _nbAccounts++;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";closed" << std::endl;
}

int Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int Account::checkAmount( void ) const
{
    return (_amount);
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    std::cout << ";deposit:" << deposit;
    if (deposit >= 0)
    {
        _totalAmount += deposit;
        _amount += deposit;
        _nbDeposits += 1;
        _totalNbDeposits += 1;
    }
    std::cout << ";amount:" << _amount;
    std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    std::cout << ";withdrawal:";
    if (withdrawal >= 0 && withdrawal <= _amount)
    {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals += 1;
        _totalNbWithdrawals += 1;
        std::cout << withdrawal;
        std::cout << ";amount:" << _amount;
        std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return (true);
    }
    else
    {
        std::cout << "refused\n";
        return (false);
    }
}


void Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:";
    std::cout << _nbAccounts;
    std::cout << ";total:";
    std::cout << _totalAmount;
    std::cout << ";deposits:";
    std::cout << _totalNbDeposits;
    std::cout << ";withdrawals:";
    std::cout << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void )
{
	time_t		timer = time(NULL);
	struct tm	*stamp = localtime(&timer);

	std::cout << "[" << (stamp->tm_year + 1900);
	std::cout << std::setfill('0') << std::setw(2) << (stamp->tm_mon + 1);
	std::cout << std::setfill('0') << std::setw(2) << stamp->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2) << stamp->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << stamp->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << stamp->tm_sec;
	std::cout << "] ";
}

void Account::displayStatus( void )const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";deposits:" << _nbDeposits;
    std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}