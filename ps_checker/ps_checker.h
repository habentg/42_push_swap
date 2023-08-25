/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:47:02 by aandom            #+#    #+#             */
/*   Updated: 2023/08/23 20:16:04 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CHECKER_H
# define PS_CHECKER_H

# include <stdlib.h>
# include <sys/types.h>
# include <limits.h>
# include <unistd.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define ERROR_MSG "Error"

# include "./../includes/libft/libft.h"

/*<>-------------struct for bonus------------------>*/
typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;
/*<--------------get_next_line funcs--------------->*/
char	*get_next_line(int fd);

/*<--------------push_swap checker funcs--------------->*/
void	check_args_bonus(int argc, char **argv);
void	apply_commands(t_list **a, t_list **b, char *cmd);
void	sort_for_check(t_list **a, t_list **b);
int		ft_strcmp(char *str1, char *str2);

// <----- LL Util functions------>
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);

// <----- Util functions------>
char	**ft_clean_argv(char **argv);
void	ft_clean_stack(t_list **stack);
void	ft_error(char *msg);
// <----- Actions------>
int		swap_command(t_list **stack);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		rotate_command(t_list **stack);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		reverse_rotate(t_list **stack);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);
int		push_command(t_list **from_stack, t_list **to_stack);
int		pa(t_list **stack_b, t_list **stack_a);
int		pb(t_list **stack_a, t_list **stack_b);
#endif
