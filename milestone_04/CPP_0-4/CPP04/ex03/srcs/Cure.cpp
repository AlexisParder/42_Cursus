/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 10:25:09 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/15 12:11:55 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") 
{
	std::cout << "Cure has been created!" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria("cure")
{
	*this = other;
	std::cout << "Cure has been copied!" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	(void)other;
	std::cout << "Cure has been assigned!" << std::endl;
    return (*this);
}

Cure::~Cure(void) 
{
	std::cout << "Cure has been destroyed!" << std::endl;
}

AMateria *Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}