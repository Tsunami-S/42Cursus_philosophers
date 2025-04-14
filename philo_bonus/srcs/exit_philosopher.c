/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:37:30 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/14 09:44:06 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	exit_philosopher(t_data *data)
{
	sem_close(data->write);
	sem_unlink("/write");
	sem_close(data->forks);
	sem_unlink("/forks");
	sem_close(data->finish);
	sem_unlink("/finish");
	exit(EXIT_SUCCESS);
}
