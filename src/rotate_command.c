/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:58:09 by mkiflema          #+#    #+#             */
/*   Updated: 2023/07/19 14:56:34 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rotate_command(t_node **stack)
{
	t_node	*head_node;
	t_node	*last_node;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	last_node = ft_lstlast(*stack);
	head_node = *stack;
	*stack = head_node->next;
	head_node->next = NULL;
	ft_lstadd_back(stack, head_node);
	if (!head_node || !last_node)
		ft_error ("rotating error!");
	return (0);
}

int	ra(t_node **stack_a)
{
	if (rotate_command(stack_a) == -1 || !stack_a)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_node **stack_b)
{
	if (rotate_command(stack_b) == -1 || !stack_b)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_node **stack_a, t_node **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	rotate_command(stack_a);
	rotate_command(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}
