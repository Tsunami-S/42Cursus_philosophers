/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:54:47 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/06 17:00:46 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_time(t_philo *philo, char *msg)
{
	long long timestamp;

	timestamp = get_current_time(philo->data) - philo->data->start_time[philo->number - 1];
	printf("%lld %d %s\n", timestamp / 1000, philo->number, msg);
}

bool is_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex->check_time);
	if(philo->data->fin)
	{
		pthread_mutex_unlock(&philo->mutex->check_time);
		return false;
	}
	pthread_mutex_unlock(&philo->mutex->check_time);
	return true;
}

void	eating(t_philo *philo, int number)
{
	int	eating;
	int time;

	pthread_mutex_lock(&philo->mutex->check_time);
	time = philo->data->time_to_eat;
	philo->data->status[number - 1] = EATING;
	if (!philo->data->fin)
	{
		print_time(philo, "has taken a fork");
		print_time(philo, "has taken a fork");
		print_time(philo, "is eating");
		philo->num_of_eating += 1;
	}
	pthread_mutex_unlock(&philo->mutex->check_time);
	pthread_mutex_lock(philo->right);
	pthread_mutex_lock(philo->left);
	eating = 0;
	while (is_alive(philo) && eating < time)
	{
		usleep(1000);
		eating++;
	}
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_lock(&philo->mutex->check_time);
	philo->data->last_eat_time[number - 1] = get_current_time(philo->data);
	pthread_mutex_unlock(&philo->mutex->check_time);
}

void	sleeping(t_philo *philo, int number)
{
	pthread_mutex_lock(&philo->mutex->check_time);
	if (!philo->data->fin)
		print_time(philo, "is sleeping");
	philo->data->status[number - 1] = SLEEPING;
	pthread_mutex_unlock(&philo->mutex->check_time);
	while (is_alive(philo) && get_current_time(philo->data)
			- philo->data->last_eat_time[number - 1] < (long long) philo->data->time_to_sleep * 1000)
		usleep(1000);
}

void	thinking(t_philo *philo, int number)
{
	pthread_mutex_lock(&philo->mutex->check_time);
	if (!philo->data->fin)
		print_time(philo, "is thinking");
	philo->data->status[number - 1] = THINKING;
	pthread_mutex_unlock(&philo->mutex->check_time);
}
