/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:01:10 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/30 08:26:03 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Colors.hpp"

Dog::Dog(void) 
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << CYAN << "Dog has been created!" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	_brain = new Brain();
	*this = other;
	std::cout << GREEN << "Dog has been copied!" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		_type = other._type;
		*_brain = *other._brain;
	}
	std::cout << MAGENTA << "Dog has been assigned!" << RESET << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << RED << "Dog has been destroyed!" << RESET << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Bark Bark" << std::endl;
}