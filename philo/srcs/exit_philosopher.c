/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:37:30 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/09 19:13:48 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_philosopher(t_data *data, t_philo **philos, int status)
{
	int		i;
	t_philo	*philo;

	pthread_mutex_destroy(&(data->mutex_status));
	pthread_mutex_destroy(&(data->mutex_time));
	pthread_mutex_destroy(&(data->mutex_permission));
	pthread_mutex_destroy(&(data->mutex_write));
	i = 0;
	while (i < data->num_of_philo)
		pthread_mutex_destroy(&(data->mutex_fork[i++]));
	free(data->mutex_fork);
	free(data->num_of_eating);
	if (philos)
	{
		philo = *philos;
		i = 0;
		while (i < data->num_of_philo)
			pthread_detach(philo[i++].thread);
		free(philo);
	}
	exit(status);
}
