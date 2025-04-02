/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:54:17 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/02 21:44:16 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// use pthread_create
// if failed to create new thread
// 		pthread_datch();
// one philosopher has one thread
// 
// use mutex_init 
// use mutex_lock to lock a timing to check dead or alive, or start eating
// (or, lock forks...?)
// if mutex is locked, other threads calling mutex is needed to wait untile unlocked
