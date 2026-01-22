/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 09:17:56 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/22 14:19:51 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	check_args(int ac, char **av)
{
	long	value;

	value = philo_long_atoi(av[1]);
	if (value < 0)
		return (0);
	value = philo_long_atoi(av[2]);
	if (value < 0)
		return (0);
	value = philo_long_atoi(av[3]);
	if (value < 0)
		return (0);
	value = philo_long_atoi(av[4]);
	if (value < 0)
		return (0);
	if (ac == 6)
	{
		value = philo_long_atoi(av[5]);
		if (value < 0)
			return (0);
	}
	return (1);
}

static void	init_data(t_philo *data, int ac, char **av)
{
	data->nb_philosophers = philo_long_atoi(av[1]);
	data->time_to_die = philo_long_atoi(av[2]);
	data->time_to_eat = philo_long_atoi(av[3]);
	data->time_to_sleep = philo_long_atoi(av[4]);
	if (ac == 6)
		data->max_meals = philo_long_atoi(av[5]);
}

int	main(int ac, char **av)
{
	t_philo	data;

	if (ac != 5 && ac != 6)
	{
		write(2, "Error: Wrong number of arguments\n", 34);
		return (1);
	}
	if (!check_args(ac, av))
	{
		write(2, "Error: please provide arguments greater than zero.\n", 52);
		return (1);
	}
	init_data(&data, ac, av);
	return (0);
}
