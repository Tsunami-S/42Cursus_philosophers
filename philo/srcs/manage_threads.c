/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:59:06 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/14 13:59:07 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	create_threads(t_philo **philos, t_data *data, int num_of_philo)
{
	int			i;
	long long	start_time;
	t_philo		*philo;

	philo = *philos;
	start_time = init_start_time(data, philos);
	data->start_time = start_time;
	if (num_of_philo == 1)
	{
		philo[0].last_eat_time = data->start_time;
		if (pthread_create(&(philo[0].thread), NULL, &routine_for_one,
				&philo[0]))
			exit_philosopher(data, philos, EXIT_FAILURE);
		return ;
	}
	i = 0;
	while (i < num_of_philo)
	{
		philo[i].last_eat_time = data->start_time;
		if (pthread_create(&(philo[i].thread), NULL, &routine, &philo[i]))
			exit_philosopher(data, philos, EXIT_FAILURE);
		i++;
	}
}

static bool	check_status(t_philo *philo, t_data *data, int num_of_philo)
{
	int			i;
	bool		bool_value;
	long long	time_to_die;
	long long	last_eat_time;

	i = 0;
	bool_value = false;
	time_to_die = get_time_data(philo, TIME_TO_DIE) * 1000;
	while (!bool_value && i < num_of_philo)
	{
		pthread_mutex_lock(&philo->data->mutex_permission);
		last_eat_time = philo[i].last_eat_time;
		pthread_mutex_unlock(&philo->data->mutex_permission);
		pthread_mutex_lock(&data->mutex_status);
		if (data->num_of_fin == num_of_philo)
			data->fin = 1;
		if (!data->fin && (get_current_time() - last_eat_time) > time_to_die)
			update_status(&philo[i], DIED);
		if (data->fin)
			bool_value = true;
		pthread_mutex_unlock(&data->mutex_status);
		i++;
	}
	return (bool_value);
}

static void	give_permission(t_philo *philo, t_data *data, int num_of_philo)
{
	int	i;

	i = 0;
	(void)data;
	while (i < num_of_philo)
	{
		pthread_mutex_lock(&philo->data->mutex_permission);
		philo[i].permission = true;
		if (philo[philo[i].left_index].last_eat_time < philo[i].last_eat_time)
			philo[i].permission = false;
		if (philo[philo[i].right_index].last_eat_time < philo[i].last_eat_time)
			philo[i].permission = false;
		if (philo[philo[i].left_index].permission)
			philo[i].permission = false;
		if (philo[philo[i].right_index].permission)
			philo[i].permission = false;
		pthread_mutex_unlock(&philo->data->mutex_permission);
		i++;
	}
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
	while (1)
	{
		if (check_status(*philo, data, num_of_philo))
			break ;
		if (num_of_philo > 1)
			give_permission(*philo, data, num_of_philo);
		usleep(300);
	}
	wait_all_exit(data, num_of_philo);
}
