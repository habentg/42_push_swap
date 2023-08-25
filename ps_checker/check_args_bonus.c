/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:31:01 by hatesfam          #+#    #+#             */
/*   Updated: 2023/08/25 09:05:36 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

static int	argv_len(char **args)
{
	int	n;

	n = 0;
	while (args[n])
		n++;
	return (n);
}

static int	ft_contains(int num, char **args, int i)
{
	while (++i < argv_len(args))
	{
		if (args[i] && (ft_atoi(args[i]) == num))
			return (1);
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (ft_strlen(num) == 0)
		ft_error(ERROR_MSG);
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_args_bonus(int argc, char **argv)
{
	char	**args;
	int		i;
	long	temp;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], 32);
	else
	{
		i = 1;
		args = argv;
	}
	if (*args == 0)
		ft_error(ERROR_MSG);
	while (args[i])
	{
		temp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]) || ((temp < INT_MIN || temp > INT_MAX)))
			ft_error(ERROR_MSG);
		else if (ft_contains(temp, args, i))
			ft_error(ERROR_MSG);
		i++;
	}
	if (argc == 2)
		ft_clean_argv(args);
}
