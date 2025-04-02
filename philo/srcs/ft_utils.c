/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:31:50 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/02 18:27:52 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isspace(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoi(const char *nptr)
{
	long long	ans;
	int			sign;

	ans = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		if (sign > 0 && (ans > LONG_MAX / 10 || (ans == LONG_MAX / 10 && *nptr
					- '0' > LONG_MAX % 10)))
			return ((int)LONG_MAX);
		else if (sign < 0 && (-ans < LONG_MIN / 10 || (-ans == LONG_MIN / 10 &&
						-(*nptr - '0') < LONG_MIN % 10)))
			return ((int)LONG_MIN);
		ans = ans * 10 + *nptr - '0';
		nptr++;
	}
	return ((int)ans * sign);
}

void	ft_putendl_fd(char *s, int fd)
{
	char *str;

	if (!s)
		return ;
	str = ft_strjoin(s, "\n");
	if(!str)
		return ;
	write(fd, str, ft_strlen(str));
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
