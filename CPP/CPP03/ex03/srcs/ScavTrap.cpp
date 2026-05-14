/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:11:26 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/14 09:51:45 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    _hit = 100;
    _energy = 50;
    _attackDmg = 20;
    std::cout << "ScavTrap " << _name << " has been created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout << "ScavTrap " << _name << " has been copied!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hit = other._hit;
        _energy = other._energy;
        _attackDmg = other._attackDmg;	
	}
	std::cout << "ScavTrap " << _name << " has been assigned!" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " has been destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_hit > 0 && _energy > 0)
	{
		_energy--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDmg << " points of damage!" << std::endl;
		return ;
	}
	if (_hit <= 0 && _energy > 0)
	{
		std::cout << "ScavTrap " << _name << " is dead and can't attack!" << std::endl;
		return ;
	}
	if (_hit > 0 && _energy <= 0)
	{
		std::cout << "ScavTrap " << _name << " has no energy left to attack!" << std::endl;
		return ;
	}
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}