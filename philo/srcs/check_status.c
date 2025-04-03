/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:55:34 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/03 23:15:26 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_alive(t_philo *philo)
{
	(void)philo;
	// if currenttime - lasttime > time to die
	//  return false
	return (true);
}

static bool	are_forks_placed(t_philo *philo, int number)
{
	if (number != philo[0].data->num_of_philo && philo[number].status == EATING)
		return (false);
	else if (philo[0].status == EATING)
		return (false);
	if (number != 1 && philo[number - 2].status == EATING)
		return (false);
	else if (philo[philo[0].data->num_of_philo - 1].status == EATING)
		return (false);
	return (true);
}

bool	check_status(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->data->check_time);
		if (!is_alive(philo))
		{
			printf("dead\n");
			pthread_mutex_unlock(&philo->data->check_time);
			return (false);
		}
		else if (are_forks_placed(philo, philo->number))
		{
			pthread_mutex_lock(philo->left);
			pthread_mutex_lock(philo->right);
			pthread_mutex_unlock(&philo->data->check_time);
			return (true);
		}
		pthread_mutex_unlock(&philo->data->check_time);
		usleep(500);
	}
}
