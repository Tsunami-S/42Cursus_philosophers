/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:54:47 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/09 00:52:41 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_time(t_philo *philo, t_type type)
{
	long long	timestamp;
	long long	start_time;

	start_time = get_time_data(philo, START_TIME);
	timestamp = (get_current_time() - start_time) / 1000;
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
}

bool	update_status(t_philo *philo, t_type type)
{
	bool		bool_value;
	long long	time_to_die;

	bool_value = true;
	time_to_die = get_time_data(philo, TIME_TO_DIE) * 1000;
	pthread_mutex_lock(&philo->data->mutex_status);
	if (!philo->data->fin
		&& (get_current_time() - philo->last_eat_time) > time_to_die)
		type = DIED;
	if (!philo->data->fin)
		print_time(philo, type);
	if (!philo->data->fin && type == DIED)
	{
		philo->data->fin = 1;
		bool_value = false;
	}
	if (!philo->data->fin && type == EATING)
	{
		philo->num_of_eating += 1;
		if (philo->num_of_eating == philo->data->num_of_must_eat)
			philo->data->num_of_fin += 1;
		philo->last_eat_time = get_current_time();
	}
	pthread_mutex_unlock(&philo->data->mutex_status);
	return (bool_value);
}
