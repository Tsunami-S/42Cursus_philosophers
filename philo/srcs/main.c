/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:32:02 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/02 19:13:43 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	validate(argc, argv);
	data = init_data(argc, argv);
	// create pthread
	// have dinner
		// print msg
	// free data (join pthread)
	printf("data[%d]\n", data.num_of_philo);
	return (EXIT_SUCCESS);
}
