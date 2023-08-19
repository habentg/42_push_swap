/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:47:02 by aandom            #+#    #+#             */
/*   Updated: 2023/08/19 23:21:14 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CHECKER_H
#define PS_CHECKER_H

# include <stdlib.h>
# include <sys/types.h>
# include <limits.h>
# include <unistd.h>
# include <sys/uio.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "./../includes/libft/libft.h"
# include "../includes/push_swap.h"

 /*<--------------get_next_line funcs--------------->*/
 char    *get_next_line(int fd);
 int	get_nl_index(char *stash);
 
 /*<--------------get_next_line util funcs--------------->*/
 
 /*<--------------push_swap checker funcs--------------->*/
 void	apply_commands(t_node **a, t_node **b, char *cmd);
 void	sort_for_check(t_node **a, t_node **b);
 int	ft_strcmp(char *str1, char *str2);
#endif
