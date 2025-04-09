/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:54:47 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/09 19:28:46 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo, int number, int num_of_philo)
{
	long long	time_to_eat;
	long long	last_eat_time;

	time_to_eat = get_time_data(philo, TIME_TO_EAT) * 1000;
	if (!get_forks(philo, number, num_of_philo))
		return ;
	pthread_mutex_lock(&philo->data->mutex_permission);
	last_eat_time = philo->last_eat_time;
	pthread_mutex_unlock(&philo->data->mutex_permission);
	while (!is_over(philo) && get_current_time() - last_eat_time < time_to_eat)
		usleep(1000);
	if (num_of_philo == 1)
		pthread_mutex_unlock(philo->left);
	else
	{
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
	}
}

void	sleeping(t_philo *philo)
{
	long long	time_to_sleep;
	long long	start_time;

	if (!update_status(philo, SLEEPING))
		return ;
	start_time = get_current_time();
	time_to_sleep = get_time_data(philo, TIME_TO_SLEEP) * 1000;
	while (!is_over(philo) && get_current_time() - start_time < time_to_sleep)
		usleep(1000);
}

void	thinking(t_philo *philo)
{
	update_status(philo, THINKING);
}
