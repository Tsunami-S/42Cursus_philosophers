/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:32:02 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/05 23:51:35 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_philo		*philo;
	pthread_t	*thread;
	t_mutex mutex;

	validate(argc, argv);
	data = init_data(argc, argv);
	mutex = init_mutex(&data);
	philo = init_philo(&data, &mutex);
	thread = create_threads(philo, &data, &mutex, data.num_of_philo);
	manage_threads(philo, &data, thread, &mutex);
	destroy_data(&data, philo, thread, data.num_of_philo, &mutex);
	return (EXIT_SUCCESS);
}
