/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:54:17 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/06 00:59:09 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//static void	*routine_for_one(t_philo *philo)
//{
//	while (1)
//	{
//		eating(philo);
//		sleeping(philo);
//		thinking(philo);
//		if (!check_status(philo))
//			break;
//	}
//	philo->leave = 1;
//	return (NULL);
//}

static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
//	if (philo->data->num_of_philo == 1)
//		return (routine_for_one(philo));
	pthread_mutex_lock(&philo->mutex->check_time);
	if (philo->number % 2 == 1)
			usleep(500);
	pthread_mutex_unlock(&philo->mutex->check_time);
	pthread_mutex_lock(&philo->mutex->check_time);
	init_start_time(philo);
	pthread_mutex_unlock(&philo->mutex->check_time);
	while (check_status(philo))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	philo->leave = 1;
	return (NULL);
}

pthread_t	*create_threads(t_philo *philo, t_data *data, t_mutex *mutex, int count)
{
	int			i;
	pthread_t	*thread;

	thread = (pthread_t *)malloc(sizeof(pthread_t) * count);
	if (!thread)
		exit(1);
	i = 0;
	while (i < count)
	{
		if (pthread_create(&thread[i], NULL, &routine, &philo[i]))
		{
			destroy_data(data, philo, thread, i, mutex);
			exit(1);
		}
		i++;
	}
	return (thread);
}
