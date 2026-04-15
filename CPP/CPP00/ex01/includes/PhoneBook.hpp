/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:34:31 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/15 13:17:45 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <Contact.hpp>
#include <iostream>
#include <iomanip>
#include <cstdlib>

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_index;
		int		_nbContacts;
		std::string	_getField(const std::string &field) const;
		std::string	_truncate(const std::string &str) const;
	public:
		PhoneBook(void);
		void	add(void);
		void	search(void) const;
};

#endif