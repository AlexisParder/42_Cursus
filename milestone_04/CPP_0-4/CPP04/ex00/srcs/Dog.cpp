/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:01:10 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/30 08:14:20 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Colors.hpp"

Dog::Dog(void) 
{
	_type = "Dog";
	std::cout << CYAN << "Dog has been created!" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	*this = other;
	std::cout << "Dog has been copied!" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
		_type = other._type;
	std::cout << "Dog has been assigned!" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << RED << "Dog has been destroyed!" << RESET << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Bark Bark" << std::endl;
}