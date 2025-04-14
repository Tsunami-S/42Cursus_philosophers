/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:44:46 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/14 10:10:54 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	exec_child_process(t_data *data, int i)
{
	data->number = i + 1;
	while (1)
	{
		eating(data);
		sleeping(data);
		thinking(data);
	}
}

void	manage_process(t_data *data)
{
	int		i;
	pid_t	*child;

	child = (pid_t *)malloc(sizeof(pid_t) * data->num_of_philo);
	if (!child)
		return ;
	data->last_eat_time = get_current_time();
	data->start_time = data->last_eat_time;
	i = 0;
	while (i < data->num_of_philo)
	{
		child[i] = fork();
		if (child[i] == 0)
			exec_child_process(data, i);
		i++;
	}
	while (i--)
		sem_wait(data->finish);
	i = 0;
	while (i < data->num_of_philo)
		kill(child[i++], SIGTERM);
	i = 0;
	while (i < data->num_of_philo)
		waitpid(child[i++], NULL, 0);
	free(child);
}
