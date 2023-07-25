/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:52:40 by kvinarao          #+#    #+#             */
/*   Updated: 2023/07/18 17:13:23 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t			count;
	unsigned char	*newstr;

	count = 0;
	newstr = (unsigned char *)str;
	while (n > count)
	{
		newstr[count] = 0;
		count++;
	}
	str = newstr;
}
