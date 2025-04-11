/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:37:30 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/10 16:08:23 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	exit_philosopher(t_data *data, t_philo **philos, int status)
{
	t_philo	*philo;

	free(data->num_of_eating);
	free(philo);
	exit(status);
}
