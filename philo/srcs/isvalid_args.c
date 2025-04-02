/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:32:33 by tssaito           #+#    #+#             */
/*   Updated: 2025/04/02 18:49:59 by tssaito          ###   ########.fr       */
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
	ft_putendl_fd("num_of_times_must_eat: 0 ~ 2147483647", STDERR_FILENO);
}

static void	print_argv_error(int index, int flag)
{
	if (!flag)
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
	else if (index == 2)
		ft_putendl_fd("time_to_die: 1 ~ 2147483647", STDERR_FILENO);
	else if (index == 3)
		ft_putendl_fd("time_to_eat: 1 ~ 2147483647", STDERR_FILENO);
	else if (index == 4)
		ft_putendl_fd("time_to_sleep: 1 ~ 2147483647", STDERR_FILENO);
	else if (index == 5)
		ft_putendl_fd("num_of_times_must_eat: 0 ~ 2147483647", STDERR_FILENO);
}

void	validate(int argc, char **argv)
{
	int	i;
	int	j;
	int	flag;
	int	num;

	if (argc != 5 && argc != 6)
	{
		in_short_of_args();
		exit(EXIT_FAILURE);
	}
	flag = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		num = ft_atoi(argv[i]);
		while (ft_isspace(argv[i][j]))
			j++;
		while (ft_isdigit(argv[i][j]))
			j++;
		if (argv[i][j] || (i < 5 && num <= 0) || (i == 5 && num < 0))
		{
			print_argv_error(i, flag);
			flag = 1;
		}
		i++;
	}
	if (flag)
		exit(EXIT_FAILURE);
}
