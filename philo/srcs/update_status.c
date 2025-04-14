/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:54:47 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/14 13:13:16 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_time(t_philo *philo, t_type type)
{
	long long	timestamp;
	long long	start_time;

	start_time = get_time_data(philo, START_TIME);
	timestamp = (get_current_time() - start_time) / 1000;
	pthread_mutex_lock(&philo->data->mutex_write);
	if (type == FORK || type == EATING)
		printf("%lld %d has taken a fork\n", timestamp, philo->number);
	if (type == EATING)
		printf("%lld %d is eating\n", timestamp, philo->number);
	else if (type == SLEEPING)
		printf("%lld %d is sleeping\n", timestamp, philo->number);
	else if (type == THINKING)
		printf("%lld %d is thinkng\n", timestamp, philo->number);
	else if (type == DIED)
		printf("%lld %d is died\n", timestamp, philo->number);
	pthread_mutex_unlock(&philo->data->mutex_write);
	if (type == DIED)
		philo->data->fin = 1;
}

bool	update_status(t_philo *philo, t_type type)
{
	int	num;

	num = philo->number - 1;
	if (type == DIED)
		return (print_time(philo, type), false);
	if (type == EATING)
	{
		pthread_mutex_lock(&philo->data->mutex_permission);
		philo->permission = false;
		pthread_mutex_unlock(&philo->data->mutex_permission);
	}
	pthread_mutex_lock(&philo->data->mutex_status);
	if (!philo->data->fin)
		print_time(philo, type);
	if (!philo->data->fin && type == EATING)
	{
		philo->data->num_of_eating[philo->number - 1] += 1;
		if (philo->data->num_of_eating[num] == philo->data->num_of_must_eat)
			philo->data->num_of_fin += 1;
		if (philo->data->num_of_fin == philo->data->num_of_philo)
			philo->data->fin = 1;
	}
	pthread_mutex_unlock(&philo->data->mutex_status);
	return (true);
}
