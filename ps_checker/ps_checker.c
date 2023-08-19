/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:42:41 by aandom            #+#    #+#             */
/*   Updated: 2023/08/20 00:09:45 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

void	rotate_both(t_node **a, t_node **b, char *cmd)
{
	if (ft_strcmp("ss\n", cmd))
	{
		sa(a);
		sb(b);
	}
	else if (ft_strcmp("rr\n", cmd))
	{
		ra(a);
		rb(b);
	}
	else if (ft_strcmp("rrr\n", cmd))
	{
		rra(a);
		rrb(b);
	}
}
void	apply_commands(t_node **a, t_node **b, char *cmd)
{
	if (ft_strcmp("ra\n", cmd))
		ra(a);
	else if (ft_strcmp("rb\n", cmd))
		rb(b);
	else if (ft_strcmp("sa\n", cmd))
		sa(a);
	else if (ft_strcmp("pa\n", cmd))
		pa(a, b);
	else if (ft_strcmp("pb\n", cmd))
		pb(a, b);
	else if (ft_strcmp("sb\n", cmd))
		sb(b);
	else if (ft_strcmp("rra\n", cmd))
		rra(a);
	else if (ft_strcmp("rrb\n", cmd))
		rrb(b);
	else if ((ft_strcmp("rrr\n", cmd)) || (ft_strcmp("rr\n", cmd)) || (ft_strcmp("ss\n", cmd)))
		rotate_both(a, b, cmd);
	else
		ft_error("INVALID INSTRUCTIO!!");
}

void	sort_for_check(t_node **a, t_node **b)
{
	char	*cmnd;
	int		fd;
	
	fd = 0;
	cmnd = get_next_line(fd);
	printf("%s \n", cmnd);
	apply_commands(a, b, cmnd);
}

int	main(int argc, char **argv)
{
	t_node	**a;
	t_node	**b;

	if (argc < 2)
		exit(0);
	check_args(argc, argv);
	a = (t_node **)ft_calloc(1, sizeof(t_node));
	b = (t_node **)ft_calloc(1, sizeof(t_node));
	stack_init(a, argc, argv);
	if (!is_sorted(a))
	{
		sort_for_check(a, b); // the whole deal here!!!
		if (is_sorted(a))
			ft_error("OK");
		else
			ft_error("KO");
	}
	ft_clean_stack(a);
	ft_clean_stack(b);
	return(0);
}