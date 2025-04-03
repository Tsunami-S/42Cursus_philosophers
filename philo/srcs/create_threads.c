/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:54:17 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/03 23:30:27 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void *routine_for_one(t_philo *philo)
{
	while (check_status(philo))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if(philo->data->num_of_philo == 1)
		return (routine_for_one(philo));
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

pthread_t	*create_threads(t_philo *philo, t_data *data)
{
	int			i;
	pthread_t	*thread;

	thread = (pthread_t *)malloc(sizeof(pthread_t) * data->num_of_philo);
	if (!thread)
		exit(1);
	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_create(&thread[i], NULL, &routine, &philo[i]))
		{
			destroy_data(data, philo, thread, i);
			exit(1);
		}
		i++;
	}
	data->set_all_dinners = 1;
	return (thread);
}
