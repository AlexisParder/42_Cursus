/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:50:05 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/08 13:03:18 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data dt;
	dt.name = "Alexis";
	dt.value = 21;


	uintptr_t ptr = Serializer::serialize(&dt);
	Data* result = Serializer::deserialize(ptr);
	
	std::cout << "serialize: " << ptr << std::endl;
	std::cout << "deserialize: " << result << std::endl;

	std::cout << result->name << std::endl;
	std::cout << result->value << std::endl;

	if (result == &dt)
    	std::cout << "Pointers are equal!" << std::endl;
	
	return 0;
}