/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:44:46 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/06 00:57:35 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// monitor all threads to check dead or alive or reached to must eat
// while(check_all_threads == all alive)
// usleep() ... how many secconds is optimal..?
// if one of threads has finished, break
// finish all threads (join)

bool is_alive_all_philo(t_philo *philo, t_mutex *mutex)
{
	int i;

	i = 0;
	pthread_mutex_lock(&mutex->check_time);
	while(i < philo[0].data->num_of_philo)
	{
		if(philo[0].data->status[i] == DEAD)
		{
			pthread_mutex_unlock(&mutex->check_time);
			return false;
		}
		i++;
	}
	pthread_mutex_unlock(&mutex->check_time);
	return true;
}

bool is_full_of_eating(t_philo *philo, t_data *data, t_mutex *mutex)
{
	int i;

	i = 0;
	pthread_mutex_lock(&mutex->check_time);
	while(i < data->num_of_philo)
	{
		if(philo[i].num_of_eating != data->num_of_must_eat)
		{
			pthread_mutex_unlock(&mutex->check_time);
			return false;
		}
		i++;
	}
	pthread_mutex_unlock(&mutex->check_time);
	return true;
}

bool is_left(t_philo *philo, t_mutex *mutex, int index)
{
	pthread_mutex_lock(&mutex->check_time);
	if(!philo[index].leave)
	{
		pthread_mutex_unlock(&mutex->check_time);
		return false;
	}
	pthread_mutex_unlock(&mutex->check_time);
	return true;
}

void	manage_threads(t_philo *philo, t_data *data, pthread_t *thread, t_mutex *mutex)
{
	int i;
	int count;

	(void)thread;
	pthread_mutex_lock(&mutex->check_time);
	count = data->num_of_philo;
	pthread_mutex_unlock(&mutex->check_time);
	while (1)
	{
		if(!is_alive_all_philo(philo, mutex) || is_full_of_eating(philo, data, mutex))
		{
			pthread_mutex_lock(&mutex->check_time);
			data->fin = 1;
			pthread_mutex_unlock(&mutex->check_time);
			i = 0;
			while(i < count)
			{
				while(!is_left(philo, mutex, i))
					usleep(300);
				i++;
			}
			return;
		}
		usleep(300);
	}
}
