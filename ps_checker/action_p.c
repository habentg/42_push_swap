/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:07:30 by hatesfam          #+#    #+#             */
/*   Updated: 2023/08/25 08:23:42 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

int	push_command(t_list **from_stack, t_list **to_stack)
{
	t_list	*from_head;

	if ((ft_lstsize(*from_stack) == 0))
		return (-1);
	from_head = *from_stack;
	*from_stack = from_head->next;
	from_head->next = 0;
	ft_lstadd_front(to_stack, from_head);
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push_command(stack_b, stack_a) == -1)
		return (-1);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push_command(stack_a, stack_b) == -1 || !stack_a || !stack_b)
		return (-1);
	return (0);
}
