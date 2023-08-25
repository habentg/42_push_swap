/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:37:00 by hatesfam          #+#    #+#             */
/*   Updated: 2023/08/25 08:19:44 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

void	rotate_both(t_list **a, t_list **b, char *cmd)
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

void	apply_commands(t_list **a, t_list **b, char *cmd)
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
	else if ((ft_strcmp("rrr\n", cmd)) || (ft_strcmp("rr\n", cmd)) || \
		(ft_strcmp("ss\n", cmd)))
		rotate_both(a, b, cmd);
	else
		ft_error(ERROR_MSG);
}

void	sort_for_check(t_list **a, t_list **b)
{
	char	*cmnd;

	cmnd = get_next_line(0);
	while (cmnd)
	{
		apply_commands(a, b, cmnd);
		cmnd = get_next_line(0);
	}
}
