/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:13:57 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/14 09:44:38 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>
# include "struct_bonus.h"

/* philo */
void		manage_process(t_data *data);
void		eating(t_data *data);
void		sleeping(t_data *data);
void		thinking(t_data *data);

/* init utils */
void		validate(int argc, char **argv);
t_data		init_data(int argc, char **argv);

/* time utils */
long long	get_current_time(void);

/* exit utils */
void		exit_philosopher(t_data *data);

/* ft_utils */
int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);
int			ft_isspace(char c);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t dsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dsize);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_itoa(int n);

#endif
