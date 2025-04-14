/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:26:06 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/14 10:06:02 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	open_semaphores(t_data *data)
{
	sem_unlink("/write");
	data->write = sem_open("/write", O_CREAT, 0644, 1);
	if (data->write == SEM_FAILED)
		exit(EXIT_FAILURE);
	sem_unlink("/forks");
	data->forks = sem_open("/forks", O_CREAT, 0644, data->num_of_philo);
	if (data->forks == SEM_FAILED)
	{
		sem_close(data->write);
		sem_unlink("/write");
		exit(EXIT_FAILURE);
	}
	sem_unlink("/finish");
	data->finish = sem_open("/finish", O_CREAT, 0644, data->num_of_philo);
	if (data->finish == SEM_FAILED)
	{
		sem_close(data->write);
		sem_unlink("/write");
		sem_close(data->forks);
		sem_unlink("/forks");
		exit(EXIT_FAILURE);
	}
}

t_data	init_data(int argc, char **argv)
{
	t_data	data;
	int		i;

	data.number = 0;
	data.num_of_eating = 0;
	data.last_eat_time = 0;
	data.start_time = 0;
	data.num_of_philo = ft_atoi(argv[1]);
	data.time_to_die = (long long)ft_atoi(argv[2]) * 1000;
	data.time_to_eat = (long long)ft_atoi(argv[3]) * 1000;
	data.time_to_sleep = (long long)ft_atoi(argv[4]) * 1000;
	data.num_of_must_eat = -1;
	if (argc == 6)
		data.num_of_must_eat = ft_atoi(argv[5]);
	open_semaphores(&data);
	i = 0;
	while (i++ < data.num_of_philo)
		sem_wait(data.finish);
	return (data);
}
