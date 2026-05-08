/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:04:21 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/08 14:02:10 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Weapon
{
	private:
		std::string _type;
 
	public:
		Weapon(const std::string &type);
		~Weapon(void);
		const std::string &getType(void) const;
		void setType(const std::string &type);
};