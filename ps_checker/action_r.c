/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:11:19 by hatesfam          #+#    #+#             */
/*   Updated: 2023/08/23 20:41:00 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

int	rotate_command(t_list **stack)
{
	t_list	*head_node;
	t_list	*last_node;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	last_node = ft_lstlast(*stack);
	head_node = *stack;
	*stack = head_node->next;
	head_node->next = 0;
	ft_lstadd_back(stack, head_node);
	if (!head_node || !last_node)
		ft_error ("rotating error!");
	return (0);
}

int	ra(t_list **stack_a)
{
	if (rotate_command(stack_a) == -1 || !stack_a)
		return (-1);
	return (0);
}

int	rb(t_list **stack_b)
{
	if (rotate_command(stack_b) == -1 || !stack_b)
		return (-1);
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	rotate_command(stack_a);
	rotate_command(stack_b);
	return (0);
}
