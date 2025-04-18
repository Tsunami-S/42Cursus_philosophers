/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:32:33 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/18 22:43:07 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	in_short_of_args(void)
{
	ft_putendl_fd("Error: In short of args", STDERR_FILENO);
	ft_putstr_fd("Example: ./philo ", STDERR_FILENO);
	ft_putstr_fd("[number_of_philosophers] ", STDERR_FILENO);
	ft_putstr_fd("[time_to_die] ", STDERR_FILENO);
	ft_putstr_fd("[time_to_eat] ", STDERR_FILENO);
	ft_putstr_fd("[time_to_sleep] ", STDERR_FILENO);
	ft_putendl_fd("([number_of_times_must_eat])", STDERR_FILENO);
	ft_putendl_fd("num_of_philosophers: 1 ~ 2147483647", STDERR_FILENO);
	ft_putendl_fd("time_to_die: 1 ~ 2147483647", STDERR_FILENO);
	ft_putendl_fd("time_to_eat: 1 ~ 2147483647", STDERR_FILENO);
	ft_putendl_fd("time_to_sleep: 1 ~ 2147483647", STDERR_FILENO);
	ft_putendl_fd("num_of_times_must_eat: 1 ~ 2147483647", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static int	print_argv_error(int index, int err_num)
{
	if (!err_num)
	{
		ft_putendl_fd("Error: Invalid arguments", STDERR_FILENO);
		ft_putstr_fd("Example: ./philo ", STDERR_FILENO);
		ft_putstr_fd("[number_of_philosophers] ", STDERR_FILENO);
		ft_putstr_fd("[time_to_die] ", STDERR_FILENO);
		ft_putstr_fd("[time_to_eat] ", STDERR_FILENO);
		ft_putstr_fd("[time_to_sleep] ", STDERR_FILENO);
		ft_putendl_fd("([number_of_times_must_eat])", STDERR_FILENO);
	}
	if (index == 1)
		ft_putendl_fd("num_of_philosophers: 1 ~ 2147483647", STDERR_FILENO);
	if (index == 2)
		ft_putendl_fd("time_to_die: 1 ~ 2147483647", STDERR_FILENO);
	if (index == 3)
		ft_putendl_fd("time_to_eat: 1 ~ 2147483647", STDERR_FILENO);
	if (index == 4)
		ft_putendl_fd("time_to_sleep: 1 ~ 2147483647", STDERR_FILENO);
	if (index == 5)
		ft_putendl_fd("num_of_times_must_eat: 1 ~ 2147483647", STDERR_FILENO);
	return (index);
}

void	validate(int argc, char **argv)
{
	int	i;
	int	j;
	int	err_num;
	int	num;

	if (argc != 5 && argc != 6)
		in_short_of_args();
	err_num = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		num = ft_atoi(argv[i]);
		while (ft_isspace(argv[i][j]))
			j++;
		while (ft_isdigit(argv[i][j]))
			j++;
		if (argv[i][j] || num <= 0)
			err_num = print_argv_error(i, err_num);
		i++;
	}
	if (err_num)
		exit(EXIT_FAILURE);
}
