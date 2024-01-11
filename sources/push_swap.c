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

static void	init_stacks(t_stack *a, t_stack *b, char **args_list);
static bool	stack_is_sorted(t_stack *stack);

int	main(int argc, char **argv)
{
	char	**args_list;
	t_stack	a;
	t_stack	b;

	args_list = NULL;
	if (!argv || argc < 2)
		ft_handle_error(ERROR_MESSAGE);
	else if (argc == 2)
		args_list = ft_split(argv[1], ' ');
	else
		args_list = argv + 1;
	check_args_list(args_list);
	init_stacks(&a, &b, args_list);
	if (!stack_is_sorted(&a))
		sort_stack(&a, &b, 0);
	//free stacks nodes
	return (EXIT_SUCCESS);
}

static void	init_stacks(t_stack *a, t_stack *b, char **args_list)
{
	t_node	*bottom_node;
	t_node	*top_node;
	t_node	*temp_node;

	bottom_node = malloc(sizeof(t_node));
	if (!bottom_node)
		return ; //TODO: Change to handle error
	*bottom_node = (t_node) {ft_atoi((*args_list)++), NULL, NULL};
	temp_node = bottom_node;
	while (*args_list)
	{
		top_node = malloc(sizeof(t_node));
		if (!top_node)
			return ; //TODO: Change to handle error
		*top_node = (t_node) {ft_atoi(*args_list), temp_node, NULL};
		temp_node->next = top_node;
		a->size++;
		args_list++;
	}
	*a = (t_stack) {a->size, top_node, bottom_node};
	*b = ((t_stack) {0, NULL, NULL});
}

static bool	stack_is_sorted(t_stack *stack)
{
	t_node	*temp_node;

	temp_node = stack->bottom;
	while (temp_node->next)
	{
		if (temp_node->value > temp_node->next->value)
			return (false);
		temp_node = temp_node->next;
	}
	return (true);
}
