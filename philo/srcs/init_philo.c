/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:26:06 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/03 23:27:49 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	exit_with_error(t_data *data, char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	destroy_data(data, NULL, NULL, 0);
	exit(EXIT_FAILURE);
}

t_philo	*init_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->num_of_philo);
	if (!philo)
		exit_with_error(data, "malloc failed");
	i = 0;
	while (i < data->num_of_philo)
	{
		philo[i].number = i + 1;
		philo[i].num_of_eating = 0;
		philo[i].last_eat_time = 0;
		philo[i].left = &data->fork[i];
		if (i == 0)
			philo[i].right = &data->fork[data->num_of_philo - 1];
		else
			philo[i].right = &data->fork[i - 1];
		philo[i].status = THINKING;
		philo[i].data = data;
		i++;
	}
	return (philo);
}
