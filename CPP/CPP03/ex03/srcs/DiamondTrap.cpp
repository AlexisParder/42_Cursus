/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 10:08:04 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/14 10:24:52 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    _hit = 100;
    _energy = 50;
    _attackDmg = 30;
    std::cout << "DiamondTrap " << _name << " has been created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
	*this = other;
	std::cout << "DiamondTrap " << _name << " has been copied!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hit = other._hit;
        _energy = other._energy;
        _attackDmg = other._attackDmg;	
	}
	std::cout << "DiamondTrap " << _name << " has been assigned!" << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " has been destroyed!" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap name: " << _name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}