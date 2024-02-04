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

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	bool	isSplit;
	char	**args_list;

	isSplit = false;
	args_list = NULL;
	if (!argv || argc < 2)
		ft_handle_error(ERROR_MESSAGE);
	else if (argc == 2) {
		args_list = ft_split(argv[1], ' ');
		isSplit = true;
	}
	else
		args_list = argv + 1;
	check_args_list(args_list, isSplit);
	init_stacks(&a, &b, args_list);
	if (!stack_is_sorted(&a))
		sort_stack(a.size ,&a, &b, 0);
	free_args_list(args_list, isSplit);
	free_nodes(a.top);
	return (EXIT_SUCCESS);
}

void	init_stacks(t_stack *a, t_stack *b, char **args_list)
{
	t_node	*new_node;
	t_node	*top_node;
	t_node	*prev_node;

	top_node = malloc(sizeof(t_node));
	if (!top_node)
		return ;
	*top_node = (t_node) {ft_atoi(*args_list++), NULL, NULL};
	prev_node = top_node;
	a->size = 1;
	while (*args_list)
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return ;
		*new_node = (t_node) {ft_atoi(*args_list), NULL, prev_node};
		prev_node->prev = new_node;
		prev_node = new_node;
		a->size++;
		args_list++;
	}
	*a = (t_stack) {a->size, top_node, prev_node};
	*b = ((t_stack) {0, NULL, NULL});
}

bool	stack_is_sorted(t_stack *stack)
{
	t_node	temp_node;

	temp_node = *stack->top;
	while (temp_node.prev)
	{
		if (temp_node.value > temp_node.prev->value)
			return (false);
		temp_node = *temp_node.prev;
	}
	return (true);
}

void	free_nodes(t_node *top_node)
{
	t_node	*temp_node;

	while (top_node)
	{
		temp_node = top_node;
		top_node = top_node->prev;
		free(temp_node);
	}
}

void	free_args_list(char **args_list, bool isSplit)
{
	if (isSplit)
	{
		ft_for_each((void **) args_list, free);
		free(args_list);
	}
}
