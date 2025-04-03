/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:37:30 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/03 11:45:17 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_data(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(data->check_time));
	while (i < data->num_of_philo)
	{
		pthread_mutex_destroy(&(data->folk[i]));
		i++;
	}
	free(data->folk);
}
