/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:07:12 by aandom            #+#    #+#             */
/*   Updated: 2023/08/23 06:52:25 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_node **stack)
{
	int	largest;

	largest = find_largest_node(stack);
	if ((*stack)->value == largest)
		ra(stack);
	else if ((*stack)->next->value == largest)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	node_init(t_node **stack_a, t_node **stack_b)
{
	index_stack(stack_b);
	index_stack(stack_a);
	set_target_node(*stack_a, *stack_b);
	set_price(*stack_a, *stack_b);
	set_cheapest(*stack_b);
}

void	sort_big(t_node **stack_a, t_node **stack_b)
{
	int		size;
	t_node	*smallest_node;

	size = ft_lstsize(*stack_a);
	while (size-- > 3)
		pb(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		node_init(stack_a, &(*stack_b));
		move_nodes(stack_a, stack_b);
	}
	index_stack(stack_a);
	smallest_node = find_smallest_node(stack_a);
	if (smallest_node->above_midpoint)
		while (*stack_a != smallest_node)
			ra(stack_a);
	else
		while (*stack_a != smallest_node)
			rra(stack_a);
}
