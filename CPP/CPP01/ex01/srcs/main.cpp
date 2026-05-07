/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:46:51 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/07 12:43:11 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

int	main(void)
{
	int	N = 5;
	Zombie *zombies = zombieHorde(N, "Horde");
	
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete[] zombies;

	return (0);
}
