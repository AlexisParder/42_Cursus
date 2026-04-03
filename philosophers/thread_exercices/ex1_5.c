/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex1_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:27:08 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/03 12:49:27 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef	struct s_philo
{
	int	id;
	long created_at;
	long started_at;
	long finished_at;
	int	total;
} t_philo;

typedef struct s_data
{
	int	nb_philos;
	pthread_t	*threads;
	t_philo		*philos;
} t_data;

long	get_time_ms(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	philo->started_at = get_time_ms();
	usleep(150000);
	philo->finished_at = get_time_ms();
	printf("Thread %d started at: %ldms\nThread %d finished at: %ldms\n", philo->id, philo->started_at - philo->created_at, philo->id, philo->finished_at - philo->started_at);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data	dt;
	int		i;

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
		dt.philos[i].created_at = get_time_ms();
		if (pthread_create(&dt.threads[i], NULL, routine, &dt.philos[i]) != 0)
		{
			printf("Error: pthread_create failed\n");
			// Il faudrait clean
			return (1);
		}
		i++;
	}
	// Wait threads
	i = 0;
	while (i < dt.nb_philos)
	{
		if (pthread_join(dt.threads[i], NULL) != 0)
		{
			printf("Error: pthread_join failed\n");
			return (1);
		}
		i++;
	}
	// Clean
	free(dt.philos);
	free(dt.threads);
	return (0);
}