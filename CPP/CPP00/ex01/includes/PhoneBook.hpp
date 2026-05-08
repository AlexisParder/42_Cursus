/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:34:31 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/08 14:03:15 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
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
		~PhoneBook(void);
		void	add(void);
		void	search(void) const;
};