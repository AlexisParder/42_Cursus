/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:47:48 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/30 08:14:16 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Colors.hpp"

Cat::Cat(void) 
{
	_type = "Cat";
	std::cout << CYAN << "Cat has been created!" << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	*this = other;
	std::cout << "Cat has been copied!" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		_type = other._type;
	std::cout << "Cat has been assigned!" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << RED << "Cat has been destroyed!" << RESET << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Miew Miew" << std::endl;
}