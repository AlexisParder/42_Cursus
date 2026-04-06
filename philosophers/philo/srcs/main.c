/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 09:17:56 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/06 09:56:57 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	check_args(int ac, char **av)
{
	long	value;

	value = philo_atol(av[1]);
	if (value <= 0)
		return (0);
	value = philo_atol(av[2]);
	if (value <= 0)
		return (0);
	value = philo_atol(av[3]);
	if (value <= 0)
		return (0);
	value = philo_atol(av[4]);
	if (value <= 0)
		return (0);
	if (ac == 6)
	{
		value = philo_atol(av[5]);
		if (value < 0)
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
	{
		print_error("Error: wrong number of arguments\n");
		return (1);
	}
	if (!check_args(ac, av))
	{
		print_error("Error: please provide arguments greater than zero.\n");
		return (1);
	}
	if (init_data(&data, ac, av))
	{
		print_error("Error: failure during data initialization.\n");
		clean_err(&data);
		return (1);
	}
	clean_all(&data);
	return (0);
}
