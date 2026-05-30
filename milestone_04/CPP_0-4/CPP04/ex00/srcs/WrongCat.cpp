/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:21:36 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/30 08:29:47 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Colors.hpp"

WrongCat::WrongCat(void) 
{
	_type = "WrongCat";
	std::cout << CYAN << "WrongCat has been created!" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	*this = other;
	std::cout << GREEN << "WrongCat has been copied!" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		_type = other._type;
	std::cout << MAGENTA << "WrongCat has been assigned!" << RESET << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << RED << "WrongCat has been destroyed!" << RESET << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Miew Miew" << std::endl;
}