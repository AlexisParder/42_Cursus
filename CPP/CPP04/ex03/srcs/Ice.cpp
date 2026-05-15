/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 10:32:00 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/15 12:10:26 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") 
{
	std::cout << "Ice has been created!" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria("ice")
{
	*this = other;
	std::cout << "Ice has been copied!" << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	(void)other;
	std::cout << "Ice has been assigned!" << std::endl;
    return (*this);
}

Ice::~Ice(void) 
{
	std::cout << "Ice has been destroyed!" << std::endl;
}

AMateria *Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}