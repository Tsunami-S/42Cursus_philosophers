/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:26:06 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/10 17:18:29 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
static void unlink_semaphore(t_data *data, int i_permission, int i_start_eating)
{
	int i;

	sem_close(&data->write);
	sem_unlink("/write");
	i = 0;
	while(i < i_permission)
	{
		sem_close(&data->permission[i]);
		sem_unlink(data->permission_name[i]);
		if(i < i_start_eating)
		{
			sem_close(&data->permission[i]);
			sem_unlink(data->permission_name[i]);
		}
	}
	free(data->permission_name);
}

static bool open_semaphore(t_data *data)
{
	int i;

	data->write = sem_open("/write", O_CREAT, 0644, 1);
	if(data.write == SEM_FAILED)
		return false;
	i = 0;
	while(i < data->num_of_philo)
	{
		data->permission[i] = sem_open("/permission", O_CREAT, 0644, 1);
		if(data->permission[i] == SEM_FAILED)
		{
			unlink_semaphores(data, i, i - 1);
			return false;
		}
		data->start_eating[i] = sem_open("/start_eating", O_CREAT, 0644, 1);
		if(data->start_eating[i] == SEM_FAILED)
		{
			unlink_semaphores(data, i, i);
			return false;
		}
		i++;
	}
	return true;
}

static t_data	init_data(int argc, char **argv)
{
	t_data	data;
	int		i;

	data.num_of_philo = ft_atoi(argv[1]);
	data.time_to_die = ft_atoi(argv[2]);
	data.time_to_eat = ft_atoi(argv[3]);
	data.time_to_sleep = ft_atoi(argv[4]);
	data.num_of_must_eat = -1;
	if (argc == 6)
		data.num_of_must_eat = ft_atoi(argv[5]);
	data.num_of_fin = 0;
	data.permission = (sem_t *)malloc(sizeof(sem_t) * data.num_of_philo);
	if(!data.permission)
		exit(EXIT_FAILURE);
	data.start_eating = (sem_t *)malloc(sizeof(sem_t) * data.num_of_philo);
	if(!data.start_eating)
	{
		free(data.permission);
		exit(EXIT_FAILURE);
	}
	return (data);
}

static t_philo	*init_philo(void)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->num_of_philo);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < data->num_of_philo)
	{
		philo[i].number = i + 1;
		philo[i].num_of_eating = 0;
		philo[i].last_eat_time = 0;
		philo[i].left_index = i - 1;
		if (i - 1 < 0)
			philo[i].left_index += data->num_of_philo;
		philo[i].right_index = (i + 1) % data->num_of_philo;
		i++;
	}
	return (philo);
}

void	init_philosopher(int argc, char **argv, t_data *data, t_philo **philo)
{
	*data = init_data(argc, argv);
	*philo = init_philo(void);
}
