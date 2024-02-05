/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:00:40 by jovicto2          #+#    #+#             */
/*   Updated: 2023/12/11 11:00:41 by jovicto2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	check_sort(t_stack *a, t_stack *b);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	bool	is_split;
	char	**args_list;

	is_split = false;
	args_list = NULL;
	if (!argv || argc == 1)
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
	free_args_list(args_list, is_split);
	read_moves(&a, &b);
	check_sort(&a, &b);
	free_nodes(a.top);
	free_nodes(b.top);
	return (EXIT_SUCCESS);
}

static void	check_sort(t_stack *a, t_stack *b)
{
	if (stack_is_sorted(a) && !b->top)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
}
