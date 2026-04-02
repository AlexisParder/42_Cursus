/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex1_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:39:10 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/02 10:08:32 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef	struct s_philo
{
	int	id;
	int	total;
} t_philo;

typedef struct s_data
{
	int	nb_philos;
	pthread_t	*threads;
	t_philo		*philos;
} t_data;

void *calc_sum(void *arg)
{
	t_philo *philo;
	int		i;
	size_t	res;

	philo = (t_philo *)arg;
	i = philo->id * 100 + 1;
	res = 0;
	while (i <= (philo->id + 1) * 100)
	{
		res += i;
		i++;
	}
	return ((void *)res);
}

int main(int ac, char **av)
{
	t_data	dt;
	int		i;
	void	*thread_return;
	size_t	res;

	if (ac != 2)
	{
		printf("Veuillez saisir le nombre de philosophe\n");
		return (1);
	}
	// Init data
	dt.nb_philos = atoi(av[1]);
	dt.threads = malloc(sizeof(pthread_t) * dt.nb_philos);
	if (!dt.threads)
	{
		printf("Erreur durant l'allocation des threads\n");
		return (1);
	}
	dt.philos = malloc(sizeof(t_philo) * dt.nb_philos);
	if (!dt.philos)
	{
		free(dt.threads);
		printf("Erreur durant l'allocation des philos\n");
		return (1);
	}
	i = 0;
	while ( i < dt.nb_philos)
	{
		dt.philos[i].id = i;
		dt.philos[i].total = dt.nb_philos;
		i++;
	}
	// Create Threads
	i = 0;
	while (i < dt.nb_philos)
	{
		if (pthread_create(&dt.threads[i], NULL, calc_sum, &dt.philos[i]) != 0)
		{
			printf("Error: pthread_create failed\n");
			// Il faudrait clean
			return (1);
		}
		i++;
	}
	// Wait threads
	i = 0;
	res = 0;
	thread_return = NULL;
	while (i < dt.nb_philos)
	{
		if (pthread_join(dt.threads[i], &thread_return) != 0)
		{
			printf("Error: pthread_join failed\n");
			return (1);
		}
		res += (size_t)thread_return;
		i++;
	}
	// Clean
	free(dt.philos);
	free(dt.threads);
	printf("Resultat = %zu\n", res);
	return (0);
}