/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 13:17:03 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/13 14:09:22 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name)
{
	_name = name;
	_hit = 10;
	_energy = 10;
	_attackDmg = 0;
	std::cout << "ClapTrap " << _name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "ClapTrap " << _name << " has been copied!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hit = other._hit;
        _energy = other._energy;
        _attackDmg = other._attackDmg;	
	}
	std::cout << "ClapTrap " << _name << " has been assigned!" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hit > 0 && _energy > 0)
	{
		_energy--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDmg << " points of damage!" << std::endl;
		return ;
	}
	if (_hit <= 0 && _energy > 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and can't attack!" << std::endl;
		return ;
	}
	if (_hit > 0 && _energy <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy left to attack!" << std::endl;
		return ;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_hit -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit > 0 && _energy > 0)
	{
		_hit += amount;
		std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points!" << std::endl;
		return ;
	}
	if (_hit <= 0 || _energy <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't repair itself!" << std::endl;
		return ;
	}
}