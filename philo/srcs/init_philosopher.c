/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:26:06 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/09 20:30:12 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static pthread_mutex_t	*init_fork(int num_of_philo)
{
	int		i;
	t_mutex	*fork;

	fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num_of_philo);
	if (!fork)
		return (NULL);
	i = 0;
	while (i < num_of_philo)
	{
		if (pthread_mutex_init(&fork[i], NULL) != 0)
		{
			while (i-- > 0)
				pthread_mutex_destroy(&fork[i]);
			free(fork);
			return (NULL);
		}
		i++;
	}
	return (fork);
}

static int	init_mutex(t_data *data, int num_of_philo)
{
	if (pthread_mutex_init(&(data->mutex_write), NULL) != 0)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&(data->mutex_permission), NULL) != 0)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&(data->mutex_time), NULL) != 0)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&(data->mutex_status), NULL) != 0)
	{
		pthread_mutex_destroy(&data->mutex_time);
		return (EXIT_FAILURE);
	}
	data->mutex_fork = init_fork(num_of_philo);
	if (!data->mutex_fork)
	{
		pthread_mutex_destroy(&data->mutex_time);
		pthread_mutex_destroy(&data->mutex_status);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
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
	data.num_of_left = 0;
	data.num_of_eating = (int *)malloc(sizeof(int) * data.num_of_philo);
	if (!data.num_of_eating)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < data.num_of_philo)
		data.num_of_eating[i++] = 0;
	data.fin = 0;
	if (init_mutex(&data, data.num_of_philo) == EXIT_FAILURE)
	{
		free(data.num_of_eating);
		exit(EXIT_FAILURE);
	}
	return (data);
}

static t_philo	*init_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->num_of_philo);
	if (!philo)
		return (exit_philosopher(data, NULL, EXIT_FAILURE), NULL);
	i = 0;
	while (i < data->num_of_philo)
	{
		philo[i].number = i + 1;
		philo[i].data = data;
		philo[i].permission = true;
		philo[i].left_index = i - 1;
		if (i - 1 < 0)
			philo[i].left_index += data->num_of_philo;
		philo[i].right_index = (i + 1) % data->num_of_philo;
		philo[i].left = &(data->mutex_fork[i]);
		philo[i].right = &(data->mutex_fork[(i + 1) % data->num_of_philo]);
		i++;
	}
	return (philo);
}

void	init_philosopher(int argc, char **argv, t_data *data, t_philo **philo)
{
	*data = init_data(argc, argv);
	*philo = init_philo(data);
}
