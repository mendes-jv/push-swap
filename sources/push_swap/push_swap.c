/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:18:11 by jovicto2          #+#    #+#             */
/*   Updated: 2023/12/07 11:18:13 by jovicto2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	bool	is_split;
	char	**args_list;

	is_split = false;
	args_list = NULL;
	if (!argv || argc < 2)
		return (EXIT_FAILURE);
	else if (argc == 2)
	{
		args_list = ft_split(argv[1], ' ');
		is_split = true;
	}
	else
		args_list = argv + 1;
	check_args_list(args_list, is_split);
	init_stacks(&a, &b, args_list);
	if (!stack_is_sorted(&a))
		sort_stack(a.size, &a, &b, 0);
	free_args_list(args_list, is_split);
	free_nodes(a.top);
	return (EXIT_SUCCESS);
}
