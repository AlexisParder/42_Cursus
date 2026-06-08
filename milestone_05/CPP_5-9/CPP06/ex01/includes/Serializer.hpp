/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:49:10 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/08 13:03:45 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Data.hpp"
#include <stdint.h>
#include <iostream>

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};