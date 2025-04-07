/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:13:57 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/06 19:05:41 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
}					t_status;

typedef struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	long long		*last_eat_time;
	long long		*start_time;
	t_status		*status;
	bool			*leave;
	bool			fin;
	bool			set_all_dinners;
}					t_data;

typedef struct s_mutex
{
	pthread_mutex_t	check_time;
	pthread_mutex_t	*fork;
}	t_mutex;

typedef struct s_philo
{
	int				number;
	int				num_of_eating;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	t_data			*data;
	t_mutex			*mutex;
}					t_philo;

#endif
