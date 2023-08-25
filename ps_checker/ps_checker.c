/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:42:41 by aandom            #+#    #+#             */
/*   Updated: 2023/08/25 08:16:59 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

static void	stack_init_bonus(t_list **stack, int argc, char **argv)
{
	char	**args;
	t_list	*new_node;
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
	if (argc == 2)
		ft_clean_argv(args);
}

static int	is_sorted_bonus(t_list **stack)
{
	t_list	*node;

	node = *stack;
	while (node->next)
	{
		if (node->content > node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	if (argc < 2)
		exit(0);
	check_args_bonus(argc, argv);
	a = (t_list **)ft_calloc(1, sizeof(t_list));
	b = (t_list **)ft_calloc(1, sizeof(t_list));
	stack_init_bonus(a, argc, argv);
	if (!is_sorted_bonus(a))
	{
		sort_for_check(a, b);
		if (is_sorted_bonus(a))
			ft_error("OK");
		else
			ft_error("KO");
	}
	ft_clean_stack(a);
	ft_clean_stack(b);
	return (0);
}
