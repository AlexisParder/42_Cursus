/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:23:14 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/08 15:00:44 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void displayStr(const std::string &str)
{
	std::cout << str << std::endl;	
}

void displayInt(const int &n)
{
    std::cout << n << std::endl;
}

int main(void) {
	{
		std::cout << "--- STRING ---" << std::endl;
		std::string arr[4] = {"alexis", "tom", "benjamin", "aliexei"};
		::iter(arr, 4, displayStr);	
	}
	{
		std::cout << "\n--- INT ---" << std::endl;
		int arr[4] = {12, 24, 48, -12};
		::iter(arr, 4, displayInt);	
	}
	return 0;
}