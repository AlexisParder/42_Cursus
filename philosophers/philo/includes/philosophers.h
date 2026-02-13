/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 09:18:08 by achauvie          #+#    #+#             */
/*   Updated: 2026/02/13 09:30:54 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_philo
{
	long	nb_philosophers;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	max_meals;
}	t_philo;

#endif