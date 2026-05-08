/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:11:39 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/08 14:02:22 by achauvie         ###   ########.fr       */
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
		Zombie(void);
		~Zombie(void);
		void setName(std::string &name);
		void announce(void);
};

Zombie *zombieHorde(int N, std::string &name);