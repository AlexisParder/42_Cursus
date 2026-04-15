/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:34:33 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/15 13:38:23 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.hpp>

Contact::Contact(void) {}

std::string	Contact::getFirstName(void) const
{
	return (_firstName);
}

std::string	Contact::getLastName(void) const
{
	return (_lastName);
}

std::string	Contact::getNickName(void) const
{
	return (_nickName);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (_phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (_darkestSecret);
}

void	Contact::setFirstName(const std::string &value)
{
	_firstName = value;
}

void	Contact::setLastName(const std::string &value)
{
	_lastName = value;
}

void	Contact::setNickName(const std::string &value)
{
	_nickName = value;
}

void	Contact::setPhoneNumber(const std::string &value)
{
	_phoneNumber = value;
}

void	Contact::setDarkestSecret(const std::string &value)
{
	_darkestSecret = value;
}
