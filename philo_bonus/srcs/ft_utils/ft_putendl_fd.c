/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:00:27 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/02 21:01:14 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	*str;

	if (!s)
		return ;
	str = ft_strjoin(s, "\n");
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
}
