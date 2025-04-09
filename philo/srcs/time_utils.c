/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:55:28 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/09 19:39:34 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	init_start_time(t_data *data, t_philo **philo)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		exit_philosopher(data, philo, EXIT_FAILURE);
	return ((long long)tv.tv_sec * 1000 * 1000 + tv.tv_usec);
}

long long	get_current_time(void)
{
	struct timeval	tv;
	long long		current_time;

	if (gettimeofday(&tv, NULL))
		return (0);
	current_time = (long long)tv.tv_sec * 1000 * 1000 + tv.tv_usec;
	return (current_time);
}

long long	get_time_data(t_philo *philo, t_data_type type)
{
	long long	time_data;

	time_data = 0;
	pthread_mutex_lock(&philo->data->mutex_time);
	if (type == TIME_TO_EAT)
		time_data = (long long)philo->data->time_to_eat;
	else if (type == TIME_TO_SLEEP)
		time_data = (long long)philo->data->time_to_sleep;
	else if (type == TIME_TO_DIE)
		time_data = (long long)philo->data->time_to_die;
	else if (type == START_TIME)
		time_data = (long long)philo->data->start_time;
	pthread_mutex_unlock(&philo->data->mutex_time);
	return (time_data);
}
