/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:14:00 by hatesfam          #+#    #+#             */
/*   Updated: 2023/08/23 20:23:44 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

int	swap_command(t_list **stack)
{
	t_list	*head_node;
	t_list	*next_node;

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

int	sa(t_list **stack_a)
{
	if (swap_command(stack_a) == -1 || !stack_a)
		return (-1);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (swap_command(stack_b) == -1 || !stack_b)
		return (-1);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	swap_command(stack_a);
	swap_command(stack_b);
	return (0);
}
