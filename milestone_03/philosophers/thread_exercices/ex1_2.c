/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex1_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:52:38 by achauvie          #+#    #+#             */
/*   Updated: 2026/03/28 14:25:59 by achauvie         ###   ########.fr       */
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

void	*routine(void *arg)
{
	t_philo *philo;
	int		i;

	philo = (t_philo *)arg;

	i = 0;
	while (i < 3)
	{
		printf("Thread %d: message %d (out of %d threads)\n", 
			philo->id, i + 1, philo->total);
		i++;
		usleep(100000);
	}
	return (NULL);
}

/**
 * 	pthread_create(
		&data.threads[i],     // Où stocker l'ID du thread
		NULL,                 // Attributs (NULL = défaut)
		routine,              // Fonction à exécuter
		&data.philos[i]       // Paramètre à passer à la fonction
	);
*/

/*
// ❌ FAUX :
...
pthread_create(..., routine, &i);  // TOUS pointent vers la même variable i !
...

// ✅ CORRECT :
...
pthread_create(..., routine, &data.philos[i]);  // Chacun a sa propre structure
...
*/
int main(int ac, char **av)
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
