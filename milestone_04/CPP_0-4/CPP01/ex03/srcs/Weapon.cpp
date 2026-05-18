/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:04:37 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/08 14:39:16 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) 
{
	_type = type;
}

Weapon::~Weapon(void) {}

const std::string &Weapon::getType(void) const
{
	return (_type);
}

void Weapon::setType(const std::string &type) 
{
	_type = type;
}
