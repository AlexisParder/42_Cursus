/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex1_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:13:12 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/03 12:30:26 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
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

void	*display_id(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *)arg;
	printf("%d\n", philo->id);
	usleep(1000000);
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
		if (pthread_create(&dt.threads[i], NULL, display_id, &dt.philos[i]) != 0)
		{
			printf("Error: pthread_create failed\n");
			// Il faudrait clean
			return (1);
		}
		pthread_detach(dt.threads[i]);
		i++;
	}
	printf("Main finished\n");
	// Clean
	free(dt.philos);
	free(dt.threads);
	return (0);
}