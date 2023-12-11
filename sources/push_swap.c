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

t_stack	*create_stack(char **args_list);

void	free_stack(t_stack *stack)
{
	t_stack	*temp_stack;

	while (stack)
	{
		temp_stack = stack;
		stack = stack->next;
		free(temp_stack);
	}
}

int	main(int argc, char **argv)
{
	char	**args_list;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!argv || argc < 2)
		ft_handle_error(ERROR_MESSAGE);
	if (argc == 2)
		args_list = split(argv[1]);
	else
		args_list = argv + 1;
	check_args(args_list);
	stack_a = create_stack(args_list);
	stack_b = NULL;
	if (args_are_sorted())
		exit(EXIT_SUCCESS);
	//TODO: create ordering algorithm
	//TODO: conditional structure to choose the best algorithm for args number
	free_stack(stack_a);
	return (EXIT_SUCCESS);
}

t_stack	*create_stack(char **args_list)
{
	t_stack	*stack;
	t_stack	*temp_stack;
	t_stack	*latest_element;

	stack = NULL;
	temp_stack = NULL;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		ft_handle_error(ERROR_MESSAGE);
	stack->value = ft_atoi(*args_list);
	stack->prev = NULL;
	stack->next = NULL;
	args_list++;

	latest_element = stack;
	while (*args_list)
	{
		temp_stack = malloc(sizeof(t_stack));
		if (!temp_stack)
			ft_handle_error(ERROR_MESSAGE);
		temp_stack->value = ft_atoi(*args_list);
		temp_stack->prev = latest_element;
		temp_stack->next = NULL;
		latest_element->next = temp_stack;
		latest_element = temp_stack;
		args_list++;
	}
	return (stack);
}
