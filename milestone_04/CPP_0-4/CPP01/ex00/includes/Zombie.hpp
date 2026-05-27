/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:11:39 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/27 13:31:06 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(const std::string &name);
		~Zombie(void);
		void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);