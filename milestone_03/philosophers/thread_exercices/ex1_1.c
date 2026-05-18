/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex1_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 22:01:50 by achauvie          #+#    #+#             */
/*   Updated: 2026/03/28 14:28:10 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

void	*func_thread1(void *arg)
{
	int i;

	i = 0;
	while (i < 50)
	{
		printf("\033[0;34mHello %d from thread!\n\033[0m", i);
		i++;
	}
	return (arg);
}

int main(void)
{
	int i;
	pthread_t	th1;

	pthread_create(&th1, NULL, func_thread1, NULL);
	i = 0;
	while (i < 50)
	{
		printf("\033[0;31mHello %d from main!\n\033[0m", i);
		i++;
	}
	pthread_join(th1, NULL);
	printf("Program finished\n");
	return (0);
}