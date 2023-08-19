/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:47:02 by aandom            #+#    #+#             */
/*   Updated: 2023/08/20 02:16:14 by hatesfam         ###   ########.fr       */
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
char	*get_next_line(int fd);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t element_count, size_t element_size);

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);

size_t	ft_strlen(const char *str);
 
 /*<--------------get_next_line util funcs--------------->*/
 
 /*<--------------push_swap checker funcs--------------->*/
 void	apply_commands(t_node **a, t_node **b, char *cmd);
 void	sort_for_check(t_node **a, t_node **b);
 int	ft_strcmp(char *str1, char *str2);
#endif
