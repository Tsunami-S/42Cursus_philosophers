/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:26:06 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/06 19:05:57 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	exit_with_error(t_data *data, char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	destroy_data(data, NULL, NULL, 0, NULL);
	exit(EXIT_FAILURE);
}

t_mutex	init_mutex(t_data *data)
{
	int	i;
	t_mutex mutex;

	if (pthread_mutex_init(&(mutex.check_time), NULL) != 0)
		exit_with_error(data, "mutex init error");
	mutex.fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->num_of_philo);
	if (!mutex.fork)
	{
		pthread_mutex_destroy(&mutex.check_time);
		exit_with_error(data, "malloc error");
	}
	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_mutex_init(&mutex.fork[i], NULL) != 0)
		{
			pthread_mutex_destroy(&mutex.check_time);
			while (i-- > 0)
				pthread_mutex_destroy(&mutex.fork[i]);
			free(mutex.fork);
			exit_with_error(data, "mutex init error");
		}
		i++;
	}
	return mutex;
}

t_philo	*init_philo(t_data *data, t_mutex *mutex)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->num_of_philo);
	if (!philo)
		exit_with_error(data, "malloc failed");
	i = 0;
	while (i < data->num_of_philo)
	{
		philo[i].number = i + 1;
		philo[i].num_of_eating = 0;
		philo[i].data = data;
		philo[i].mutex = mutex;
		philo[i].left = &(mutex->fork[i]);
		if (i == 0)
			philo[i].right = &(mutex->fork[data->num_of_philo - 1]);
		else
			philo[i].right = &(mutex->fork[i - 1]);
		i++;
	}
	return (philo);
}
