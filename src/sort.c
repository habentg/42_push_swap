/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:07:12 by aandom            #+#    #+#             */
/*   Updated: 2023/07/25 20:46:22 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    sort_three(t_node **stack)
{
    int largest;

    largest = find_largest_node(stack);
    if ((*stack)->value == largest)
        ra(stack);
    else if ((*stack)->next->value == largest)
        rra(stack);
    if ((*stack)->value > (*stack)->next->value)
        sa(stack);
}

void    sort_big(t_node **stack_a, t_node **stack_b)
{
    int size;
    t_node *temp_b;
    
    size = ft_lstsize(*stack_a);
    temp_b = *stack_b;
    while (size-- > 3)
    {
        pb(stack_a, stack_b);
    }
    sort_three(stack_a);
    printf("we here..");
    while (temp_b)
    {
        index_stack(&temp_b);
        index_stack(stack_a);
        target_node(stack_a, &temp_b);
        printf("target node working\n");
        push_cost(stack_a, &temp_b);
        set_cheapest(&temp_b);
        temp_b = temp_b->next;
    }
    printf("node targeted! i guess\n");
}