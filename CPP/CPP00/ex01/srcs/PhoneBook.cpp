/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:34:35 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/06 15:20:59 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>

PhoneBook::PhoneBook(void)
{
	_index = 0;
	_nbContacts = 0;
}

PhoneBook::~PhoneBook(void){}

std::string	PhoneBook::_getField(const std::string &field) const
{
	std::string	value;

	std::cout << field;
	std::getline(std::cin, value);
	while (value.empty())
	{
		if (std::cin.eof())
        {
            std::cout << std::endl;
            std::exit(0);
        }
		std::cout << "Field cannot be empty!" << std::endl;
		std::getline(std::cin, value);
	}
	return (value);
}

void	PhoneBook::add(void)
{
	_contacts[_index].setFirstName(_getField("First name: "));
	_contacts[_index].setLastName(_getField("Last name: "));
	_contacts[_index].setNickName(_getField("Nick name: "));
	_contacts[_index].setPhoneNumber(_getField("Phone number: "));
	_contacts[_index].setDarkestSecret(_getField("Darkest secret: "));
	if (_nbContacts < 8)
		_nbContacts++;
	_index = (_index + 1) % 8;
}

std::string	PhoneBook::_truncate(const std::string &str) const
{
	if (str.size() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::search(void) const
{
	int	i = 0;
	std::string	input;

	while (i < _nbContacts)
	{
		std::cout << std::right;
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << _truncate(_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << _truncate(_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << _truncate(_contacts[i].getNickName()) << "|";
		std::cout << std::endl;
		i++;
	}
	std::cout << "Enter index: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		std::exit(0);
	}
	i = std::atoi(input.c_str());
	if (i < 0 || i >= _nbContacts)
	{
		std::cout << "That contact does not exist!" << std::endl;
		return ;
	}
	std::cout << "Index: " << i << std::endl;
	std::cout << "First name: " << _contacts[i].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[i].getLastName() << std::endl;
	std::cout << "Nick name: " << _contacts[i].getNickName() << std::endl;
	std::cout << "Phone number: " << _contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[i].getDarkestSecret() << std::endl;
}
