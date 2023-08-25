/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:35:42 by aandom            #+#    #+#             */
/*   Updated: 2023/08/25 09:59:51 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_target_node(t_node *stack_a, t_node *stack_b)
{
	t_node	*current_a;
	t_node	*target_node;
	int		targ_node_val;

	while (stack_b)
	{
		targ_node_val = INT_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > stack_b->value
				&& current_a->value < targ_node_val)
			{
				targ_node_val = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (targ_node_val == INT_MAX)
			stack_b->target_node = find_smallest_node(&stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	set_price(t_node *stack_a, t_node *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	while (stack_b)
	{
		stack_b->total_push_cost = stack_b->current_index;
		if (!(stack_b->above_midpoint))
			stack_b->total_push_cost = size_b - (stack_b->current_index);
		if (stack_b->target_node->above_midpoint)
			stack_b->total_push_cost += stack_b->target_node->current_index;
		else
			stack_b->total_push_cost += size_a - \
				(stack_b->target_node->current_index);
		stack_b = stack_b->next;
	}
}

void	set_cheapest(t_node *stack)
{
	int		node_cost;
	t_node	*cheapest_node;

	node_cost = INT_MAX;
	cheapest_node = stack;
	cheapest_node->cheapest = 0;
	while (stack)
	{
		if (stack->total_push_cost < node_cost)
		{
			node_cost = stack->total_push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}
