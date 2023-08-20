/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:56:28 by aandom            #+#    #+#             */
/*   Updated: 2023/08/20 15:07:31 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_node	*return_cheapest(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->cheapest == 1)
			return (temp);
		temp = temp->next;
	}
	return (0);
}

static void	rotate_both(t_node **stack_a, \
	t_node **stack_b, t_node *cheapest_push)
{
	while (((*stack_a)->target_node != cheapest_push) \
		&& ((*stack_b) != cheapest_push))
		rr(stack_a, stack_b);
	index_stack(stack_a);
	index_stack(stack_b);
}

static void	r_rotate_both(t_node **stack_a, t_node **stack_b, \
	t_node *cheapest_push)
{
	while (((*stack_a)->target_node != cheapest_push) && \
		((*stack_b) != cheapest_push))
		rrr(stack_a, stack_b);
	index_stack(stack_a);
	index_stack(stack_b);
}

void	more_rotation(t_node **stack, t_node *wanted_node, char stack_name)
{
	while ((*stack) != wanted_node)
	{
		if (stack_name == 'a')
		{
			if (wanted_node->above_midpoint)
				ra(stack);
			else
				rra(stack);
		}
		if (stack_name == 'b')
		{
			if (wanted_node->above_midpoint)
				rb(stack);
			else
				rrb(stack);
		}
		index_stack(stack);
	}
}

void	move_nodes(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest_push;

	cheapest_push = return_cheapest(*stack_b);
	if (cheapest_push->above_midpoint
		&& cheapest_push->target_node->above_midpoint)
		rotate_both(stack_a, stack_b, cheapest_push);
	else if (!(cheapest_push->above_midpoint)
		&& !(cheapest_push->target_node->above_midpoint))
		r_rotate_both(stack_a, stack_b, cheapest_push);
	more_rotation(stack_b, cheapest_push, 'b');
	more_rotation(stack_a, cheapest_push->target_node, 'a');
	pa(stack_a, stack_b);
}
