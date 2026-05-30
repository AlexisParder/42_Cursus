/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:45:15 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/30 08:27:57 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Colors.hpp"

Animal::Animal(void) 
{
	std::cout << BLUE << "Animal has been created!" << RESET << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << GREEN << "Animal has been copied!" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		_type = other._type;
	std::cout << MAGENTA << "Animal has been assigned!" << RESET << std::endl;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << RED << "Animal has been destroyed!" << RESET << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType(void) const
{
    return (_type);
}