/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:04:48 by hatesfam          #+#    #+#             */
/*   Updated: 2023/08/23 20:41:21 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

int	reverse_rotate(t_list **stack)
{
	t_list	*head_node;
	t_list	*last_node;
	t_list	*temp;
	t_list	*one_before_last;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head_node = *stack;
	last_node = ft_lstlast(*stack);
	temp = head_node;
	one_before_last = 0;
	while (temp->next)
	{
		one_before_last = temp;
		temp = temp->next;
	}
	one_before_last->next = 0;
	if (!head_node || !last_node || !temp || !one_before_last)
		ft_error ("rotating error!");
	*stack = last_node;
	ft_lstadd_back(stack, head_node);
	return (0);
}

int	rra(t_list **stack_a)
{
	if (reverse_rotate(stack_a) == -1 || !stack_a)
		return (-1);
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (reverse_rotate(stack_b) == -1 || !stack_b)
		return (-1);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	return (0);
}
