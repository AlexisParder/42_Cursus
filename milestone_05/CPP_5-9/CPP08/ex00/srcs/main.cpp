/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 09:13:10 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/10 09:38:25 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main(void)
{
	{
		std::cout << "--- Value doesn't exist ---" << std::endl;
		std::vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i);
		try 
		{
			easyfind(vec, 12);
			std::cout << "Value found!" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n--- Value exist ---" << std::endl;
		std::vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i);
		try 
		{
			std::cout << "Found: " << *easyfind(vec, 5) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}