/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:47:48 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/30 08:32:29 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Colors.hpp"

Cat::Cat(void) 
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << CYAN << "Cat has been created!" << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	_brain = new Brain();
	*this = other;
	std::cout << GREEN << "Cat has been copied!" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		_type = other._type;
		*_brain = *other._brain;
	}
	std::cout << MAGENTA << "Cat has been assigned!" << RESET << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << RED << "Cat has been destroyed!" << RESET << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Miew Miew" << std::endl;
}