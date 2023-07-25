/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:35:42 by aandom            #+#    #+#             */
/*   Updated: 2023/07/25 20:44:32 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    target_node(t_node **stack_a, t_node **stack_b)
{
    int best_match_value;
    t_node *temp_a;
    t_node *temp_b;
    
    temp_a = *stack_a;
    temp_b = *stack_b;
    while (temp_b)
    {
        best_match_value = INT_MAX;
        while (temp_a)
        {
            if (temp_a->value > temp_b->value && temp_a->value < best_match_value)
            {
                temp_b->target_node = temp_a;
                best_match_value = temp_a->value;
            }
            temp_a = temp_a->next;
        }
        if (best_match_value == INT_MAX)
            temp_b->target_node = find_smallest_node(stack_a);
        temp_b = temp_b->next;
    }
}

void    push_cost(t_node **stack_a, t_node **stack_b)
{
    int size_a;
    int size_b;
    t_node  *temp_b;

    size_a = ft_lstsize(*stack_a);
    size_b = ft_lstsize(*stack_b);
    temp_b = *stack_b;
    while (temp_b)
    {
        temp_b->total_push_cost = temp_b->current_index;
        if (!(temp_b->above_midpoint))
            temp_b->total_push_cost = size_b - (temp_b->current_index);
        if (temp_b->target_node->above_midpoint)
            temp_b->total_push_cost+=temp_b->target_node->current_index;
        else
            temp_b->total_push_cost+=(size_a - temp_b->target_node->current_index);
        temp_b = temp_b->next;
    }
}

void    set_cheapest(t_node **stack)
{
    t_node *temp;
    t_node *cheapest_node;
    int     cheap_cost;
    
    temp = *stack;
    cheap_cost = INT_MAX;
    while (temp)
	{
		if (temp->total_push_cost < cheap_cost)
		{
			cheap_cost = temp->total_push_cost;
			cheapest_node = temp;
		}
		temp = temp->next;
	}
    cheapest_node->cheapest = 1;
}