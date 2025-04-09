/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:54:17 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/09 20:09:56 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_over(t_philo *philo)
{
	bool	bool_value;

	bool_value = true;
	pthread_mutex_lock(&philo->data->mutex_status);
	if (!philo->data->fin)
		bool_value = false;
	pthread_mutex_unlock(&philo->data->mutex_status);
	return (bool_value);
}

void	*routine_for_one(void *arg)
{
	int		number;
	t_philo	*philo;

	philo = (t_philo *)arg;
	number = 1;
	while (1)
	{
		eating(philo, number, ALONE);
		sleeping(philo);
		thinking(philo);
		if (is_over(philo))
			break ;
	}
	pthread_mutex_lock(&philo->data->mutex_status);
	philo->data->num_of_left += 1;
	pthread_mutex_unlock(&philo->data->mutex_status);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		number;

	philo = (t_philo *)arg;
	number = philo->number;
	if (number % 2 == 0)
		usleep(300);
	while (1)
	{
		eating(philo, number, NOT_ALONE);
		sleeping(philo);
		thinking(philo);
		if (is_over(philo))
			break ;
	}
	pthread_mutex_lock(&philo->data->mutex_status);
	philo->data->num_of_left += 1;
	pthread_mutex_unlock(&philo->data->mutex_status);
	return (NULL);
}
