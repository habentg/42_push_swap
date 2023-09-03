/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:03:42 by aandom            #+#    #+#             */
/*   Updated: 2023/08/25 09:04:10 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	argv_len(char **args)
{
	int	n;

	n = 0;
	while (args[n])
		n++;
	return (n);
}

static bool	ft_contains(int num, char **args, int i)
{
	while (++i < argv_len(args))
	{
		if (args[i] && (ft_atoi(args[i]) == num))
			return (true);
	}
	return (false);
}

static bool	ft_isnum(char *num)
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
			return (false);
		i++;
	}
	return (true);
}

void	check_args(int argc, char **argv)
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
	if (*args == NULL)
		ft_error("Error");
	while (args[i])
	{
		temp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ft_error(ERROR_MSG);
		else if (ft_contains(temp, args, i))
			ft_error(ERROR_MSG);
		i++;
	}
	if (argc == 2)
	 	ft_clean_argv(args);
}
