/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:54:17 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/09 00:09:04 by tssaito          ###   ########.fr       */
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

static void	*routine_for_one(t_philo *philo)
{
	int	number;

	number = 1;
	while (!is_over(philo))
	{
		eating(philo, number, ALONE);
		sleeping(philo);
		thinking(philo);
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
	if (philo->data->num_of_philo == 1)
		return (routine_for_one(philo));
	number = philo->number;
	if (number % 2)
		usleep(200);
	while (!is_over(philo))
	{
		eating(philo, number, NOT_ALONE);
		sleeping(philo);
		thinking(philo);
	}
	pthread_mutex_lock(&philo->data->mutex_status);
	philo->data->num_of_left += 1;
	pthread_mutex_unlock(&philo->data->mutex_status);
	return (NULL);
}
