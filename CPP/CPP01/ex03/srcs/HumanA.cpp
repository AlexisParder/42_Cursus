/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:04:23 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/11 09:09:32 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name), _weapon(weapon)
{}

HumanA::~HumanA(void) {}

void HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
