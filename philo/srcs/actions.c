/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:54:47 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/09 00:48:41 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	return_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

bool	get_forks(t_philo *philo, int number, int num_of_philo)
{
	t_mutex	*first;
	t_mutex	*seccond;

	first = philo->right;
	seccond = philo->left;
	if (number % 2)
	{
		first = philo->left;
		seccond = philo->right;
	}
	pthread_mutex_lock(first);
	if (num_of_philo == ALONE && !update_status(philo, EATING))
		return (pthread_mutex_unlock(first), false);
	if (num_of_philo != ALONE)
	{
		if (!update_status(philo, FORK))
			return (pthread_mutex_unlock(first), false);
		pthread_mutex_lock(seccond);
		if (!update_status(philo, EATING))
			return (return_forks(philo), false);
	}
	return (true);
}

void	eating(t_philo *philo, int number, int num_of_philo)
{
	long long	time_to_eat;
	long long	time_to_die;

	time_to_eat = get_time_data(philo, TIME_TO_EAT) * 1000;
	time_to_die = get_time_data(philo, TIME_TO_DIE) * 1000;
	if (!get_forks(philo, number, num_of_philo))
		return ;
	while (!is_over(philo))
	{
		if (get_current_time() - philo->last_eat_time > time_to_eat)
			break ;
		else if (get_current_time() - philo->last_eat_time > time_to_die)
			break ;
		else
			usleep(1000);
	}
	if (num_of_philo == 1)
		pthread_mutex_unlock(philo->left);
	else
		return_forks(philo);
}

void	sleeping(t_philo *philo)
{
	long long	time_to_sleep;
	long long	time_to_die;
	long long	start_time;

	if (!update_status(philo, SLEEPING))
		return ;
	start_time = get_current_time();
	time_to_sleep = get_time_data(philo, TIME_TO_SLEEP) * 1000;
	time_to_die = get_time_data(philo, TIME_TO_DIE) * 1000;
	while (!is_over(philo))
	{
		if (get_current_time() - start_time > time_to_sleep)
			break ;
		else if (get_current_time() - philo->last_eat_time > time_to_die)
			break ;
		else
			usleep(1000);
	}
}

void	thinking(t_philo *philo)
{
	long long	time_to_eat;
	long long	time_to_die;

	time_to_eat = get_time_data(philo, TIME_TO_EAT) * 1000;
	time_to_die = get_time_data(philo, TIME_TO_DIE) * 1000;
	update_status(philo, THINKING);
	while (!is_over(philo))
	{
		if (get_current_time() - philo->last_eat_time > time_to_eat * 2)
			break ;
		else if (get_current_time() - philo->last_eat_time > time_to_die)
			break ;
		else
			usleep(1000);
	}
	usleep(1000);
}
