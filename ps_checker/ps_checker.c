/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:42:41 by aandom            #+#    #+#             */
/*   Updated: 2023/08/04 10:59:36 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

void	apply_commands(t_list **a, t_list **b, char *cmd)
{
	// apply all the commands/instructions on the stacks
	// then it should be sorted, .....
}

void	sort_for_check(t_list **a, t_list **b)
{
	char	*cmnd;
	int		fd;
	
	fd = 0;
	// read all the commands/instrutions using get_next_line (each line is an instruction)
	cmnd = get_next_line(fd);
	
	apply_commands(a, b, cmnd);
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	if (argc < 2)
		exit(0);
	check_args(argc, argv);
	a = (t_list **)calloc(1, sizeof(t_list));
	b = (t_list **)calloc(1, sizeof(t_list));
	stack_init(a, argc, argv);
	if (!is_sorted(a))
	{
		sort_for_check(a, b); // the whole deal here!!!
		if (is_sorted(a))
			ft_error("OK");
		else
			ft_error("KO");
		ft_clean_stack(a);
		if (b)
			ft_clean_stack(b);
		exit (0);
	}
	ft_clean_stack(a);
	return(0);
}