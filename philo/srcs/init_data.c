/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:26:06 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/03 11:44:15 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void exit_with_error(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void init_mutex(t_data *data)
{
	int i;

	if (pthread_mutex_init(&(data->check_time), NULL) != 0)
		exit_with_error("mutex init error");
	data->folk = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	if(!data->folk)
		exit_with_error("malloc error");
	i = 0;
	while(i < data->num_of_philo)
	{
		if (pthread_mutex_init(&(data->folk[i]), NULL) != 0)
			exit_with_error("mutex init error");
		i++;	
	}
}

t_data	init_data(int argc, char **argv)
{
	t_data	data;

	data.num_of_philo = ft_atoi(argv[1]);
	data.time_to_die = ft_atoi(argv[2]);
	data.time_to_eat = ft_atoi(argv[3]);
	data.time_to_sleep = ft_atoi(argv[4]);
	data.num_of_must_eat = -1;
	if (argc == 6)
		data.num_of_must_eat = ft_atoi(argv[5]);
	init_mutex(&data);
	return (data);
}
