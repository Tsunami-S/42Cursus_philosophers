/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:55:34 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/06 00:26:03 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_alive(t_philo *philo)
{
	if((get_current_time(philo->data) - philo->start_time) / 1000 < (long long)philo->data->time_to_die)
		return (true);
	return (false);
}

bool	are_forks_placed(t_philo *philo, int number, t_data *data)
{
	(void)philo;
	if (number != data->num_of_philo && data->status[number - 1] == EATING)
		return (false);
	else if (number == data->num_of_philo && data->status[0] == EATING)
		return (false);
	if (number != 1 && data->status[number - 2] == EATING)
		return (false);
	else if (number == 1 && data->status[number - 1] == EATING)
		return (false);
	return (true);
}

bool	check_status(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->mutex->check_time);
		if (philo->data->fin)
		{
			pthread_mutex_unlock(&philo->mutex->check_time);
			return (false);
		}
		if (!is_alive(philo))
		{
			if (!philo->data->fin)
				printf("%lld %d is died\n", (get_current_time(philo->data) - philo->start_time) / 1000, philo->number);
			philo->data->fin = 1;
			philo->data->status[philo->number - 1] = DEAD;
			pthread_mutex_unlock(&philo->mutex->check_time);
			return (false);
		}
		else if (are_forks_placed(philo, philo->number, philo->data))
		{
			philo->data->status[philo->number - 1] = EATING;
			pthread_mutex_unlock(&philo->mutex->check_time);
			return (true);
		}
		pthread_mutex_unlock(&philo->mutex->check_time);
		usleep(500);
	}
}
