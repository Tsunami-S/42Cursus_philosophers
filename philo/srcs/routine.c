/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:54:47 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/03 23:15:15 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	waiting(t_philo *philo)
{
	while (!philo->data->set_all_dinners)
		usleep(500);
}

static void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->check_time);
	printf("time eating[%d]\n", philo->number);
	pthread_mutex_unlock(&philo->data->check_time);
	philo->status = EATING;
	usleep(philo->data->time_to_eat * 1000);
	philo->num_of_eating += 1;
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	//	philo->last_eat_time = get_current_time();
}

static void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->check_time);
	printf("time sleeping\n");
	pthread_mutex_unlock(&philo->data->check_time);
	philo->status = SLEEPING;
	usleep(philo->data->time_to_sleep * 1000);
}

static void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->check_time);
	printf("time thinking\n");
	pthread_mutex_unlock(&philo->data->check_time);
	philo->status = THINKING;
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	//	if(philo->data->num_of_philo == 1)
	//		return (one_philo(philo));
	if (philo->number % 2)
		waiting(philo);
	while (check_status(philo))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
