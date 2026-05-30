/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 10:13:23 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/30 08:45:53 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Colors.hpp"

AMateria::AMateria(std::string const &type)
{
	_type = type;
	std::cout << BLUE << "AMateria " << _type << " has been created!" << RESET << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
	std::cout << GREEN << "AMateria " << _type << " has been copied!" << RESET << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	(void)other;
	std::cout << MAGENTA << "AMateria has been assigned!" << RESET << std::endl;
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << RED << "AMateria " << _type << " has been destroyed!" << RESET << std::endl;
}

std::string const &AMateria::getType(void) const
{
	return (_type);
}

void AMateria::use(ICharacter &target)
{
    (void)target;
}