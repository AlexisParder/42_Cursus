/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 09:17:56 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/09 09:30:03 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	check_args_digit(char **av)
{
	size_t	i;
	size_t	j;
	long	tmp_nbr;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '+' || av[i][j] == '-')
			j++;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (1);
			j++;
		}
		tmp_nbr = philo_atol(av[i]);
		if (tmp_nbr < -2147483648 || tmp_nbr > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

static int	check_args(int ac, char **av)
{
	if (check_args_digit(av))
	{
		write_fd(2, "Error: arguments must be integers.\n");
		return (1);
	}
	if (philo_atol(av[1]) <= 0 || philo_atol(av[2]) <= 0
		|| philo_atol(av[3]) <= 0 || philo_atol(av[4]) <= 0)
	{
		write_fd(2, "Error: arguments must be positive integers.\n");
		return (1);
	}
	if (ac == 6)
	{
		if (philo_atol(av[5]) < -1)
		{
			write_fd(2, "Error: arguments must be positive integers.\n");
			return (1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
	{
		write_fd(2, "Error: invalid number of arguments.\n");
		return (1);
	}
	if (check_args(ac, av))
		return (1);
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
