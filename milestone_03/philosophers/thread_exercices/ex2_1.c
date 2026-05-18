/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex2_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:52:38 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/03 13:13:26 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int counter = 0;

typedef struct s_data
{
	int	id;
	pthread_t	tid;
} t_data;

void	*routine(void *arg)
{
	(void)arg;
	int	i = 0;
	while (i < 10000)
	{
		counter++;
		i++;
	}
	return (NULL);
}

int main(int ac, char **av)
{
	t_data	*dt;
	int		i;

	if (ac != 2)
	{
		printf("Veuillez saisir le nombre de philosophe\n");
		return (1);
	}
	// Init data
	int n = atoi(av[1]);
	dt = malloc(sizeof(t_data) * n);
	if (!dt)
	{
		printf("Erreur durant l'allocation des threads\n");
		return (1);
	}
	// Create Threads
	i = 0;
	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, NULL);
	while (i < n)
	{
		dt[i].id = i;
		if (pthread_create(&dt[i].tid, NULL, routine, &dt[i]) != 0)
		{
			printf("Error: pthread_create failed\n");
			// Il faudrait clean
			return (1);
		}
		i++;
	}
	// Wait threads
	i = 0;
	while (i < n)
	{
		if (pthread_join(dt[i].tid, NULL) != 0)
		{
			printf("Error: pthread_join failed\n");
			return (1);
		}
		i++;
	}
	printf("Resultat = %d\n", counter);
	// Clean
	free(dt);
	return (0);
}
