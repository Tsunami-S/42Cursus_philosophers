/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:32:02 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/10 16:07:05 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	validate(argc, argv);
	init_philosopher(argc, argv, &data, &philo);
	manage_threads(&philo, &data);
	exit_philosopher(&data, &philo, EXIT_SUCCESS);
}
