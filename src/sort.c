/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:07:12 by aandom            #+#    #+#             */
/*   Updated: 2023/07/26 22:31:16 by aandom           ###   ########.fr       */
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

static void node_init(t_node **stack_a, t_node **stack_b)
{
    index_stack(stack_b);
    index_stack(stack_a);
    target_node(stack_a, stack_b);
    push_cost(stack_a, stack_b);
    set_cheapest(stack_b);
}
void    sort_big(t_node **stack_a, t_node **stack_b)
{
    int size;
    t_node  *temp_b;
    // t_node  *smallest_node;
    
    size = ft_lstsize(*stack_a);
    temp_b = *stack_b;
    while (size-- > 3)
    {
        pb(stack_a, stack_b);
    }
    // sort_three(stack_a);
    while (*stack_b)
    {
        printf("number of nodes - b: %d\n", ft_lstsize(*stack_b));
		print_node_val(stack_b);
        printf("number of nodes - a: %d\n", ft_lstsize(*stack_a));
		print_node_val(stack_a);
        node_init(stack_a, &(*stack_b));
        printf("number of nodes - b - after node init: %d\n", ft_lstsize(*stack_b));
		print_node_val(stack_b);
        printf("number of nodes - a - after node init: %d\n", ft_lstsize(*stack_a));
		print_node_val(stack_a);
        // smallest_node = find_smallest_node(stack_b);
        printf("node value: %d\n", (*stack_b)->value);
        printf("node above mp: %d\n", (*stack_b)->above_midpoint);
        printf("node cheap: %d\n", (*stack_b)->cheapest);
        printf("node index: %d\n", (*stack_b)->current_index);
        printf("node push cost: %d\n", (*stack_b)->total_push_cost);
        printf("target_node value: %d\n", (*stack_b)->target_node->value);
        move_nodes(stack_a, &(*stack_b));
        print_node_val(stack_a);
		print_node_val(stack_b);
        (*stack_b) = (*stack_b)->next;
    }
    *stack_b = temp_b;
    printf("number of nodes - b: %d\n", ft_lstsize(*stack_b));
    index_stack(stack_a);
    printf("almost last \n");
    print_node_val(stack_a);
    print_node_val(stack_b);
    // smallest_node = find_smallest_node(stack_b);
    // if (smallest_node->above_midpoint)
    // {
	// 	while (*stack_a != smallest_node)
    //     {
	// 		ra(stack_a);
    //         (*stack_a) = (*stack_a)->next;
    //     }   
    // }
	// else
    // {
	// 	while (*stack_a != smallest_node)
    //     {
	// 		rra(stack_a);
    //         (*stack_a) = (*stack_a)->next;
    //     }
    // }
}