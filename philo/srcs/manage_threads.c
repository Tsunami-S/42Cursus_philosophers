/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:44:46 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/09 10:49:56 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long	init_start_time(t_data *data, t_philo **philo)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		exit_philosopher(data, philo, EXIT_FAILURE);
	return ((long long)tv.tv_sec * 1000 * 1000 + tv.tv_usec);
}

static void	create_threads(t_philo **philos, t_data *data, int num_of_philo)
{
	int			i;
	long long	start_time;
	t_philo		*philo;

	i = 0;
	philo = *philos;
	start_time = init_start_time(data, philos);
	data->start_time = start_time;
	while (i < num_of_philo)
	{
		philo[i].last_eat_time = data->start_time;
		if (pthread_create(&(philo[i].thread), NULL, &routine, &philo[i]))
			exit_philosopher(data, philos, EXIT_FAILURE);
		i++;
	}
}

static bool	is_all_over(t_philo *philo, int num_of_philo)
{
	bool	bool_value;

	bool_value = false;
	pthread_mutex_lock(&philo->data->mutex_status);
	if (philo->data->num_of_fin == num_of_philo)
		philo->data->fin = 1;
	if (philo->data->fin)
		bool_value = true;
	pthread_mutex_unlock(&philo->data->mutex_status);
	return (bool_value);
}

static void	wait_all_exit(t_data *data, int num_of_philo)
{
	int	num_of_left;

	while (1)
	{
		pthread_mutex_lock(&data->mutex_status);
		num_of_left = data->num_of_left;
		pthread_mutex_unlock(&data->mutex_status);
		if (num_of_left == num_of_philo)
			break ;
		usleep(300);
	}
}

void	manage_threads(t_philo **philo, t_data *data)
{
	int	num_of_philo;

	num_of_philo = data->num_of_philo;
	create_threads(philo, data, num_of_philo);
	while (!is_all_over(*philo, num_of_philo))
		usleep(100);
	wait_all_exit(data, num_of_philo);
}
