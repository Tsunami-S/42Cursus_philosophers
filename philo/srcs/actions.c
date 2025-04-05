/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:54:47 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/06 00:30:35 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_time(t_philo *philo, char *msg)
{
	long long timestamp;

	timestamp = get_current_time(philo->data) - philo->start_time;
	printf("%lld %d %s\n", timestamp / 1000, philo->number, msg);
}

void	eating(t_philo *philo)
{
	int	eating;

	pthread_mutex_lock(&philo->mutex->check_time);
	philo->data->status[philo->number - 1] = EATING;
	if (!philo->data->fin)
	{
		print_time(philo, "has taken a fork");
		print_time(philo, "has taken a fork");
		print_time(philo, "is eating");
		philo->num_of_eating += 1;
	}
	pthread_mutex_unlock(&philo->mutex->check_time);
	eating = 0;
	pthread_mutex_lock(philo->left);
	pthread_mutex_lock(philo->right);
	while (!philo->data->fin && eating < philo->data->time_to_eat)
	{
		usleep(1000);
		eating++;
	}
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	philo->last_eat_time = get_current_time(philo->data);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex->check_time);
	if (!philo->data->fin)
		print_time(philo, "is sleeping");
	philo->data->status[philo->number - 1] = SLEEPING;
	pthread_mutex_unlock(&philo->mutex->check_time);
	while (!philo->data->fin &&  get_current_time(philo->data)
			- philo->last_eat_time < (long long) philo->data->time_to_sleep * 1000)
		usleep(1000);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex->check_time);
	if (!philo->data->fin)
		print_time(philo, "is thinking");
	philo->data->status[philo->number - 1] = THINKING;
	pthread_mutex_unlock(&philo->mutex->check_time);
}
