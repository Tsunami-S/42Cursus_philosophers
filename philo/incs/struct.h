/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:13:57 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/03 14:12:51 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	bool			set_all_dinners;
	pthread_mutex_t	check_time;
	pthread_mutex_t	*fork;
}					t_data;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
}					t_status;

typedef struct s_philo
{
	int				number;
	int				num_of_eating;
	int				last_eat_time;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	t_status		status;
	t_data			*data;
}					t_philo;

#endif
