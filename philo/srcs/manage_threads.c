/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:44:46 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/02 21:56:08 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// monitor all threads to check dead or alive or reached to must eat
// while(check_all_threads == all alive)
// usleep() ... how many secconds is optimal..?
// if one of threads has finished, break
// finish all threads (join)
