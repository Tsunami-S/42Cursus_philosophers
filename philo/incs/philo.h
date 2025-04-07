/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:13:57 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/06 16:28:57 by tssaito          ###   ########.fr       */
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
pthread_t	*create_threads(t_philo *philo, t_data *data, t_mutex *mutex, int count);
bool		check_status(t_philo *philo, int number);
void		manage_threads(t_philo *philo, t_data *data, pthread_t *thread, t_mutex *mutex);
void		eating(t_philo *philo, int number);
void		sleeping(t_philo *philo, int number);
void		thinking(t_philo *philo, int number);
bool	are_forks_placed(t_philo *philo, int number, t_data *data);

/* time utils */
int init_start_time(t_philo *philo);
long long	get_current_time(t_data *data);

/* init utils */
void		validate(int argc, char **argv);
t_data		init_data(int argc, char **argv);
t_mutex	init_mutex(t_data *data);
t_philo		*init_philo(t_data *data, t_mutex *mutex);

/* exit utils */
void		destroy_data(t_data *data, t_philo *philo, pthread_t *thread,
				int count, t_mutex *mutex);

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
