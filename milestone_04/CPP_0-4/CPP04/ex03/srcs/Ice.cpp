/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 10:32:00 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/30 08:51:14 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Colors.hpp"

Ice::Ice(void) : AMateria("ice") 
{
	std::cout << CYAN << "Ice has been created!" << RESET << std::endl;
}

Ice::Ice(const Ice &other) : AMateria("ice")
{
	*this = other;
	std::cout << GREEN << "Ice has been copied!" << RESET << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	(void)other;
	std::cout << MAGENTA << "Ice has been assigned!" << RESET << std::endl;
    return (*this);
}

Ice::~Ice(void) 
{
	std::cout << RED << "Ice has been destroyed!" << RESET << std::endl;
}

AMateria *Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}