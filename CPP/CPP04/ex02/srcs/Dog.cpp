/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:01:10 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/15 09:58:46 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) 
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog has been created!" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	_brain = new Brain();
	*this = other;
	std::cout << "Dog has been copied!" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		_type = other._type;
		*_brain = *other._brain;
	}
	std::cout << "Dog has been assigned!" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog has been destroyed!" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Bark Bark" << std::endl;
}