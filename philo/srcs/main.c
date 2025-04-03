/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:32:02 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/03 23:14:50 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_philo		*philo;
	pthread_t	*thread;

	validate(argc, argv);
	data = init_data(argc, argv);
	philo = init_philo(&data);
	thread = create_threads(philo, &data);
	manage_threads(philo, &data, thread);
	destroy_data(&data, philo, thread, data.num_of_philo);
	return (EXIT_SUCCESS);
}
