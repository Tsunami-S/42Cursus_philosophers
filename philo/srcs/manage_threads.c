/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:44:46 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/03 23:14:09 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// monitor all threads to check dead or alive or reached to must eat
// while(check_all_threads == all alive)
// usleep() ... how many secconds is optimal..?
// if one of threads has finished, break
// finish all threads (join)

void	manage_threads(t_philo *philo, t_data *data, pthread_t *thread)
{
	int	i;

	(void)thread;
	while (1)
	{
		i = 0;
		while (i < data->num_of_philo)
		{
			// if(philo[i].status == DEAD)
			// detach():
			if (philo[i].num_of_eating == 5)
				return ;
			i++;
		}
	}
}
