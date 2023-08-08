/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:46:16 by aandom            #+#    #+#             */
/*   Updated: 2023/08/08 09:13:14 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

int	ft_strcmp(char *str1, char *str2)
{
	if (ft_strlen(str1) != ft_strlen(str2))
		return (0);
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	if ((!*str1 && !*str2))
		return (1);
	return (0);
}

void	stack_init(t_node **stack, int argc, char **argv)
{
	char	**args;
	t_node	*new_node;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], 32);
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new_node = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new_node);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_clean_argv(args);
}
