/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 09:17:56 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/06 15:09:32 by achauvie         ###   ########.fr       */
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
		if (value < -1)
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
	{
		write_fd(2, "Error: invalid number of arguments.\n");
		return (1);
	}
	if (!check_args(ac, av))
	{
		write_fd(2, "Error: arguments must be positive integers.\n");
		return (1);
	}
	if (init_data(&data, ac, av))
	{
		write_fd(2, "Error: data initialization failed.\n");
		clean_err(&data);
		return (1);
	}
	if (manage_threads(&data))
	{
		write_fd(2, "Error: thread creation failed.\n");
		return (1);
	}
	clean_all(&data);
	return (0);
}
