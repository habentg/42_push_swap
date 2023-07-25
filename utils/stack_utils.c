/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:04:39 by aandom            #+#    #+#             */
/*   Updated: 2023/07/25 20:20:45 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    index_stack(t_node **stack)
{
    int i;
    t_node	*temp;
    int     midpoint;

	temp = *stack;
    i = 0;
    midpoint = ft_lstsize(temp) / 2;
    while (temp)
    {
        temp->current_index = i;
        if (i <= midpoint)
			temp->above_midpoint = 1;
		else
			temp->above_midpoint = 0;
        temp = temp->next;
        i++;
    } 
}

int find_largest_node(t_node **stack)
{
    int     biggest;
    t_node  *current_node;
    current_node = *stack;
    biggest = current_node->value;
    
    while (current_node)
    {
        if (current_node->value > biggest)
            biggest = current_node->value;
        current_node = current_node->next;
    }
    return (biggest);    
}

t_node *find_smallest_node(t_node **stack)
{
    t_node  *smallest;
    t_node  *current_node;

    current_node = *stack;
    smallest = current_node;
    while (current_node)
    {
        if (current_node->value < smallest->value)
            smallest = current_node;
        current_node = current_node->next;
    }
    return (smallest);
}

int    find_index(t_node **stack, int val)
{
    t_node  *head;
    int     index;
    
    index = 0;
    head = *stack;
    while (head)
    {
        if (head->value == val)
        {
            index = head->current_index;
            return (index);
        }
        head = head->next;
    }
    return (-1);
}