/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:47:48 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/15 09:58:04 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) 
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat has been created!" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	_brain = new Brain();
	*this = other;
	std::cout << "Cat has been copied!" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		_type = other._type;
		*_brain = *other._brain;
	}
	std::cout << "Cat has been assigned!" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat has been destroyed!" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Miew Miew" << std::endl;
}