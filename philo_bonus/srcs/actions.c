/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:54:47 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/14 10:23:51 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	print_time(t_data *data, t_type type)
{
	long long	timestamp;

	timestamp = (get_current_time() - data->start_time) / 1000;
	if (type == EATING)
	{
		printf("%lld %d has taken a fork\n", timestamp, data->number);
		if (data->num_of_philo != 1)
			printf("%lld %d has taken a fork\n", timestamp, data->number);
		printf("%lld %d is eating\n", timestamp, data->number);
	}
	else if (type == SLEEPING)
		printf("%lld %d is sleeping\n", timestamp, data->number);
	else if (type == THINKING)
		printf("%lld %d is thinkng\n", timestamp, data->number);
	else if (type == DIED)
		printf("%lld %d is died\n", timestamp, data->number);
}

static void	is_over(t_data *data)
{
	int	i;

	if (get_current_time() - data->last_eat_time < data->time_to_die)
		return ;
	sem_wait(data->write);
	print_time(data, DIED);
	i = 0;
	while (data->num_of_philo)
	{
		sem_post(data->finish);
		i++;
	}
	exit(EXIT_SUCCESS);
}

void	eating(t_data *data)
{
	sem_wait(data->forks);
	if (data->num_of_philo != 1)
		sem_wait(data->forks);
	is_over(data);
	sem_wait(data->write);
	print_time(data, EATING);
	sem_post(data->write);
	data->num_of_eating += 1;
	if (data->num_of_eating == data->num_of_must_eat)
		sem_post(data->finish);
	data->last_eat_time = get_current_time();
	while (get_current_time() - data->last_eat_time < data->time_to_eat)
		usleep(1000);
	is_over(data);
	sem_post(data->forks);
	sem_post(data->forks);
}

void	sleeping(t_data *data)
{
	is_over(data);
	sem_wait(data->write);
	print_time(data, SLEEPING);
	sem_post(data->write);
	while (get_current_time() - data->last_eat_time < data->time_to_eat
		+ data->time_to_sleep)
		usleep(1000);
}

void	thinking(t_data *data)
{
	is_over(data);
	sem_wait(data->write);
	print_time(data, THINKING);
	sem_post(data->write);
}
