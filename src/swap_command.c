/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:15:46 by hatesfam          #+#    #+#             */
/*   Updated: 2023/07/18 11:15:46 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	swap_command(t_node **stack)
{
	t_node	*head_node;
	t_node	*next_node;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head_node = *stack;
	next_node = head_node->next;
	if (!head_node || !next_node)
		ft_error ("swaping error!");
	head_node->next = next_node->next;
	ft_lstadd_front(stack, next_node);
	return (0);
}

int	sa(t_node **stack_a)
{
	if (swap_command(stack_a) == -1 || !stack_a)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_node **stack_b)
{
	if (swap_command(stack_b) == -1 || !stack_b)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_node **stack_a, t_node **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	swap_command(stack_a);
	swap_command(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
