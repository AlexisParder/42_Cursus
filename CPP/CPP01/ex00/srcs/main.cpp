/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:11:29 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/07 10:44:07 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

int	main(void)
{
	Zombie *zombies[5];
	for (int i = 0; i < 5; i++)
	{
		zombies[i] = newZombie("HeapZombie");
		zombies[i]->announce();
	}
	for (int i = 0; i < 5; i++)
    	delete zombies[i];
	for (int i = 0; i < 5; i++)
    	randomChump("StackZombie");
	return (0);
}