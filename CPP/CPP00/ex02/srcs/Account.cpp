/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 08:53:35 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/15 13:33:10 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Account.hpp>

Account::Account(void) {}

Account::Account(int initial_deposit)
{
	
}

Account::~Account(void){}

void	Account::_displayTimestamp(void)
{
	
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	
}

void	Account::makeDeposit(int deposit)
{
	
}

bool	Account::makeWithdrawal(int withdrawal)
{
	
}

int	Account::checkAmount(void) const
{
	
}

void	Account::displayStatus(void) const
{
	
}