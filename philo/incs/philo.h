/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:13:57 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/09 00:49:07 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include "struct.h"

/* philo */
void		manage_threads(t_philo **philo, t_data *data);
bool		is_over(t_philo *philo);
bool		is_died(t_philo *philo);
bool		check_status(t_philo *philo);
void		*routine(void *arg);
void		eating(t_philo *philo, int number, int num_of_philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
bool		update_status(t_philo *philo, t_type type);

/* init utils */
void		validate(int argc, char **argv);
void		init_philosopher(int argc, char **argv, t_data *data,
				t_philo **philo);

/* time utils */
long long	get_current_time(void);
long long	get_time_data(t_philo *philo, t_data_type type);
long long	get_timestamp(t_philo *philo);

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
