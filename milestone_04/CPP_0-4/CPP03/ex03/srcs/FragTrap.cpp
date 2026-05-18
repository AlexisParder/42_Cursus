/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 09:57:04 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/14 10:02:01 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    _hit = 100;
    _energy = 100;
    _attackDmg = 30;
    std::cout << "FragTrap " << _name << " has been created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap " << _name << " has been copied!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hit = other._hit;
        _energy = other._energy;
        _attackDmg = other._attackDmg;	
	}
	std::cout << "FragTrap " << _name << " has been assigned!" << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " has been destroyed!" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (_hit > 0 && _energy > 0)
	{
		_energy--;
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDmg << " points of damage!" << std::endl;
		return ;
	}
	if (_hit <= 0 && _energy > 0)
	{
		std::cout << "FragTrap " << _name << " is dead and can't attack!" << std::endl;
		return ;
	}
	if (_hit > 0 && _energy <= 0)
	{
		std::cout << "FragTrap " << _name << " has no energy left to attack!" << std::endl;
		return ;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " is requesting a high five! Who's with me?" << std::endl;
}