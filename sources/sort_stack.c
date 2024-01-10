/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:00:40 by jovicto2          #+#    #+#             */
/*   Updated: 2023/12/11 11:00:41 by jovicto2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	stack_is_sorted(t_stack *stack);

void	sort_stack(t_stack *a, t_stack *b)
{
	if (stack_is_sorted(a))
		ft_handle_error(ERROR_MESSAGE);
	if (a->size <= 5)
		small_stack_sort(a, b);
	else
		big_stack_sort(a, b);
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