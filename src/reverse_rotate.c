/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:52:30 by mkiflema          #+#    #+#             */
/*   Updated: 2023/07/19 20:28:29 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	reverse_rotate(t_node **stack)
{
	t_node	*head_node;
	t_node	*last_node;
	t_node	*temp;
	t_node	*one_before_last;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head_node = *stack;
	last_node = ft_lstlast(*stack);
	temp = head_node;
	one_before_last = NULL;
	while (temp->next != NULL)
	{
		one_before_last = temp;
		temp = temp->next;
	}
	one_before_last->next = NULL;
	if (!head_node || !last_node || !temp || !one_before_last)
		ft_error ("rotating error!");
	*stack = last_node;
	ft_lstadd_back(stack, head_node);
	return (0);
}

int	rra(t_node **stack_a)
{
	if (reverse_rotate(stack_a) == -1 || !stack_a)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_node **stack_b)
{
	if (reverse_rotate(stack_b) == -1 || !stack_b)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_node **stack_a, t_node **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
