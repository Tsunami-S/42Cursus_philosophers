/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:28:57 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/09 19:30:42 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_forks(t_philo *philo, int number, t_mutex **first,
		t_mutex **seccond)
{
	if (number % 2)
	{
		*first = philo->left;
		*seccond = philo->right;
	}
	else
	{
		*first = philo->right;
		*seccond = philo->left;
	}
}

static bool	wait_permission(t_philo *philo)
{
	while (1)
	{
		if (is_over(philo))
			return (false);
		pthread_mutex_lock(&philo->data->mutex_permission);
		if (philo->permission == true)
			break ;
		pthread_mutex_unlock(&philo->data->mutex_permission);
		usleep(300);
	}
	return (true);
}

bool	get_forks(t_philo *philo, int number, int num_of_philo)
{
	t_mutex	*first;
	t_mutex	*seccond;

	set_forks(philo, number, &first, &seccond);
	if (!wait_permission(philo))
		return (false);
	pthread_mutex_unlock(&philo->data->mutex_permission);
	pthread_mutex_lock(first);
	if (num_of_philo == ALONE && !update_status(philo, EATING))
		return (pthread_mutex_unlock(first), false);
	else if (num_of_philo == ALONE)
		return (true);
	if (!update_status(philo, FORK))
		return (pthread_mutex_unlock(first), false);
	pthread_mutex_lock(seccond);
	if (!update_status(philo, EATING))
	{
		pthread_mutex_unlock(first);
		pthread_mutex_unlock(seccond);
		return (false);
	}
	pthread_mutex_lock(&philo->data->mutex_permission);
	philo->last_eat_time = get_current_time();
	pthread_mutex_unlock(&philo->data->mutex_permission);
	return (true);
}
