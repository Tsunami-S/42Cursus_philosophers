/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:37:30 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/03 21:51:17 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_data(t_data *data, t_philo *philo, pthread_t *thread, int count)
{
	int	i;

	pthread_mutex_destroy(&(data->check_time));
	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_destroy(&(data->fork[i]));
		i++;
	}
	free(data->fork);
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
		free(thread);
	}
}
