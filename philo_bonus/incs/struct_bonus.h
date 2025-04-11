/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:13:57 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/10 17:16:22 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

typedef pthread_mutex_t	t_mutex;

typedef enum e_type
{
	FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
}						t_type;

typedef enum e_num_of_philo
{
	NOT_ALONE,
	ALONE,
}						t_num_of_philo;

typedef enum e_data_type
{
	START_TIME,
	TIME_TO_EAT,
	TIME_TO_SLEEP,
	TIME_TO_DIE,
	LAST_EAT_TIME,
}						t_data_type;

typedef struct s_data
{
	int					num_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_of_must_eat;
	int					num_of_fin;
	int					num_of_left;
	long long			start_time;
	char *permission_name;
	char *start_eating_name;
	sem_t write;
	sem_t *permission;
	sem_t *start_eating;
}						t_data;

typedef struct s_philo
{
	int					number;
	int					left_index;
	int					right_index;
	int					num_of_eating;
	long long			last_eat_time;
}						t_philo;

#endif
