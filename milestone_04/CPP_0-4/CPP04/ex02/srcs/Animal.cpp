/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:45:15 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/15 10:03:11 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) 
{
	std::cout << "Animal has been created!" << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << "Animal has been copied!" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		_type = other._type;
	std::cout << "Animal has been assigned!" << std::endl;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal has been destroyed!" << std::endl;
}

std::string Animal::getType(void) const
{
    return (_type);
}