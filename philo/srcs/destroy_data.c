/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:37:30 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/05 23:03:24 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_data(t_data *data, t_philo *philo, pthread_t *thread, int count, t_mutex *mutex)
{
	int	i;

	pthread_mutex_destroy(&(mutex->check_time));
	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_destroy(&(mutex->fork[i]));
		i++;
	}
	free(mutex->fork);
	if (philo)
		free(philo);
	if (thread)
	{
		i = 0;
		while (i < count)
		{
			pthread_detach(thread[i]);
			i++;
		}
		(void)count;
		free(thread);
	}
}
