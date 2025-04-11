/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:13:57 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/10 16:56:34 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <fcntl.h>
# include <semaphore.h>
# include "struct_bonus.h"

/* philo */
void		manage_threads(t_philo **philo, t_data *data);
void		*routine(void *arg);
void		*routine_for_one(void *arg);
bool		get_forks(t_philo *philo, int number, int num_of_philo);
void		eating(t_philo *philo, int number, int num_of_philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
bool		is_over(t_philo *philo);
bool		update_status(t_philo *philo, t_type type);

/* init utils */
void		validate(int argc, char **argv);
void		init_philosopher(int argc, char **argv, t_data *data,
				t_philo **philo);

/* time utils */
long long	init_start_time(t_data *data, t_philo **philo);
long long	get_current_time(void);
long long	get_time_data(t_philo *philo, t_data_type type);

/* exit utils */
void		exit_philosopher(t_data *data, t_philo **philos, int status);

/* ft_utils */
int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);
int			ft_isspace(char c);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t dsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dsize);

#endif
