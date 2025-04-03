/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:54:47 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/03 10:07:56 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// start_routine is handed to pthread_create
// routine get one param(void *)
// each philosopher use this func at each thread

// required informations(t_philo?)
// philo's number
// mutex
// current status(eating, sleeping, thinking)
// count of eating(if argv[5] is existing)

// philosophers sitting side by side are not able to eating at the same time
// so, how can I adjust their eating timing?

void *routine(void *arg)
{
	//philo = (t_philo)arg;
	//
	// while(alive)
	// 	eat -> sleep -> think (usleep)
	// check dead or alive (or reached to num_must_eat)
	// dead or finished -> return(return value is used as exit status)
}
