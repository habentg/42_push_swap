/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:01:16 by aandom            #+#    #+#             */
/*   Updated: 2023/07/26 22:19:34 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	stack_init(t_node **stack, int argc, char **argv)
{
	char	**args;
	t_node	*new_node;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], 32);
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new_node = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new_node);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_clean_argv(args);
}


static bool	is_sorted(t_node **stack)
{
	t_node	*current_node;

	current_node = *stack;
	while (current_node)
	{
		if (current_node->value > current_node->next->value)
			return (false);
		current_node = current_node->next;
	}
	return (true);
}

static void    lets_sort(t_node **stack_a, t_node **stack_b)
{
    int stack_a_size;

    stack_a_size = ft_lstsize(*stack_a);
    if (stack_a_size <= 3)
    {
        sort_three(stack_a);
        exit (0);
    }
    else
        sort_big(stack_a, stack_b);
}

void	print_node_val(t_node **stack)
{
	t_node	*temp;
	
	temp = *stack;
    printf("stack: ");
    while (temp)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
    printf("\n");
}

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;

	if (argc < 2)
		exit(0);
	check_args(argc, argv);
	stack_a = (t_node **)calloc(1, sizeof(t_node));
	stack_b = (t_node **)calloc(1, sizeof(t_node));
	stack_init(stack_a, argc, argv);
	if (!is_sorted(stack_a))
	{
		lets_sort(stack_a, stack_b);
		// print_node_val(stack_a);
		// print_node_val(stack_b);
		ft_clean_stack(stack_a);
		if (stack_b)
			ft_clean_stack(stack_b);
		exit (0);
	}
	ft_clean_stack(stack_a);
	return (0);
}