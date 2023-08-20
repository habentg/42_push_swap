/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:46:16 by aandom            #+#    #+#             */
/*   Updated: 2023/08/20 15:17:42 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

int	ft_strcmp(char *str1, char *str2)
{
	if (ft_strlen(str1) != ft_strlen(str2))
		return (0);
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	if ((!*str1 && !*str2))
		return (1);
	return (0);
}
