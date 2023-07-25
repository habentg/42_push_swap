/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:44:58 by mkiflema          #+#    #+#             */
/*   Updated: 2023/07/19 13:50:07 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_lstnew(int content)
{
	t_node	*link;

	link = (t_node *)malloc(sizeof(t_node));
	if (!link)
		return (NULL);
	link->value = content;
	link->next = NULL;
	return (link);
}

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	if (!new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
		(ft_lstlast(*lst)->next = new);
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	if (lst != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

int	ft_lstsize(t_node *lst)
{
	size_t	count;
	t_node	*temp;

	temp = lst;
	count = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}
