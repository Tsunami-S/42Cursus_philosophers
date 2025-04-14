/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:13:57 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/14 14:04:08 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

typedef enum e_type
{
	FORK,
	EATING,
	EATING_ALONE,
	SLEEPING,
	THINKING,
	DIED,
}				t_type;

typedef struct s_data
{
	int			number;
	int			num_of_philo;
	int			*pid;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	int			num_of_must_eat;
	int			num_of_eating;
	long long	last_eat_time;
	long long	start_time;
	sem_t		*write;
	sem_t		*forks;
	sem_t		*finish;
}				t_data;

#endif
