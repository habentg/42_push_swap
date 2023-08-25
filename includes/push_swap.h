/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:45:07 by hatesfam          #+#    #+#             */
/*   Updated: 2023/07/14 00:45:07 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR_MSG "Error"

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				current_index;
	int				above_midpoint;
	int				total_push_cost;
	int				cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
}	t_node;

// <----- Util functions------>
void	check_args(int argc, char **argv);
char	**ft_clean_argv(char **argv);
void	ft_clean_stack(t_node **stack);
void	ft_error(char *msg);

// <----- LL Util functions------>
t_node	*ft_lstnew(int content);
t_node	*ft_lstlast(t_node *lst);
int		ft_lstsize(t_node *lst);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *new);

// <----- stack functions------>
void	stack_init(t_node **stack, int argc, char **argv);
void	index_stack(t_node **stack);
int		find_largest_node(t_node **stack);
t_node	*find_smallest_node(t_node **stack);
int		find_index(t_node **stack, int val);
void	set_target_node(t_node *stack_a, t_node *stack_b);
void	set_price(t_node *stack_a, t_node *stack_b);
void	set_cheapest(t_node *stack);
void	move_nodes(t_node **stack_a, t_node **stack_b);
void	more_rotation(t_node **stack, t_node *wanted_node, char stack_name);
void	node_init(t_node **stack_a, t_node **stack_b);

// <----- Algorithm implementation------>
void	sort_three(t_node **stack);
void	sort_big(t_node **stack_a, t_node **stack_b);
int		is_sorted(t_node **stack);
void	lets_sort(t_node **stack_a, t_node **stack_b);
// <----- Actions------>
int		swap_command(t_node **stack);
int		sa(t_node **stack_a);
int		sb(t_node **stack_b);
int		ss(t_node **stack_a, t_node **stack_b);
int		rotate_command(t_node **stack);
int		ra(t_node **stack_a);
int		rb(t_node **stack_b);
int		rr(t_node **stack_a, t_node **stack_b);
int		reverse_rotate(t_node **stack);
int		rra(t_node **stack_a);
int		rrb(t_node **stack_b);
int		rrr(t_node **stack_a, t_node **stack_b);
int		push_command(t_node **from_stack, t_node **to_stack);
int		pa(t_node **stack_b, t_node **stack_a);
int		pb(t_node **stack_a, t_node **stack_b);
/// testing
void	print_node_val(t_node **stack);
#endif