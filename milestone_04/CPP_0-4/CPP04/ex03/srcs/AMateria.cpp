/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 10:13:23 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/15 12:08:58 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	_type = type;
	std::cout << "AMateria " << _type << " has been created!" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
	std::cout << "AMateria " << _type << " has been copied!" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	(void)other;
	std::cout << "AMateria has been assigned!" << std::endl;
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria " << _type << " has been destroyed!" << std::endl;
}

std::string const &AMateria::getType(void) const
{
	return (_type);
}

void AMateria::use(ICharacter &target)
{
    (void)target;
}