/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:26:06 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/06 15:24:47 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	init_data(int argc, char **argv)
{
	int i;
	t_data	data;

	data.num_of_philo = ft_atoi(argv[1]);
	data.time_to_die = ft_atoi(argv[2]);
	data.time_to_eat = ft_atoi(argv[3]);
	data.time_to_sleep = ft_atoi(argv[4]);
	data.num_of_must_eat = -1;
	data.set_all_dinners = 0;
	data.fin = 0;
	if (argc == 6)
		data.num_of_must_eat = ft_atoi(argv[5]);
	data.status = (t_status *)malloc(sizeof(t_status) * data.num_of_philo);
	if(!data.status)
	{
		exit(1);
	}
	i = 0;
	data.leave = (bool *)malloc(sizeof(bool) * data.num_of_philo);
	data.start_time = (long long *)malloc(sizeof(long long) * data.num_of_philo);
	data.last_eat_time = (long long *)malloc(sizeof(long long) * data.num_of_philo);
	while(i < data.num_of_philo)
	{
		data.status[i] = THINKING;
		data.leave[i] = 0;
		i++;
	}
	return (data);
}
