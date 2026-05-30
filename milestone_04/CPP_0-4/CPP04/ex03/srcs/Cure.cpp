/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 10:25:09 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/30 08:50:40 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Colors.hpp"

Cure::Cure(void) : AMateria("cure") 
{
	std::cout << CYAN << "Cure has been created!" << RESET << std::endl;
}

Cure::Cure(const Cure &other) : AMateria("cure")
{
	*this = other;
	std::cout << GREEN << "Cure has been copied!" << RESET << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	(void)other;
	std::cout << MAGENTA << "Cure has been assigned!" << RESET << std::endl;
    return (*this);
}

Cure::~Cure(void) 
{
	std::cout << RED << "Cure has been destroyed!" << RESET << std::endl;
}

AMateria *Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}