/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:46:51 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/07 13:25:03 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

int	main(void)
{
	int	N = 5;
	std::string name = "Horde";
	Zombie *zombies = zombieHorde(N, name);
	
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete[] zombies;

	return (0);
}
