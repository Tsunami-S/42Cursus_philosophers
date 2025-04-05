/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:55:28 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/05 22:14:39 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_current_time(t_data *data)
{
	struct timeval tv;
	long long current_time;

	(void)data;
	if(gettimeofday(&tv, NULL))
		exit(1);
	current_time = (long long)tv.tv_sec * 1000 * 1000 + tv.tv_usec;
	return (current_time);
}

int init_start_time(t_philo *philo)
{
	struct timeval tv;

	if(gettimeofday(&tv, NULL))
		return (1);
	philo->start_time = (long long)tv.tv_sec * 1000 * 1000 + tv.tv_usec;
	return (0);
}
