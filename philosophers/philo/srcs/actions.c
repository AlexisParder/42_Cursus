/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 09:36:04 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/07 14:55:36 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	start_eat(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (philo->id - 1 < philo->data->nb_philos)
	{
		first = philo->left_fork;
		second = philo->right_fork;
	}
	else
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}
	pthread_mutex_lock(first);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(second);
	print_action(philo, "has taken a fork");
	print_action(philo, "is eating");
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_time_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	ft_usleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_unlock(second);
	pthread_mutex_unlock(first);
}

void	philo_eat(t_philo *philo)
{
	if (philo->data->nb_philos == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		ft_usleep(philo->data->time_to_die, philo->data);
		pthread_mutex_unlock(philo->left_fork);
		print_action(philo, "died");
		set_dead(philo->data);
		return ;
	}
	start_eat(philo);
}

void	philo_sleep(t_philo *philo)
{
	if (is_dead(philo->data))
        return ;
	print_action(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep, philo->data);
}

void	philo_think(t_philo *philo)
{
	if (is_dead(philo->data))
        return ;
	print_action(philo, "is thinking");
}
