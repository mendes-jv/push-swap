/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:27:02 by jovicto2          #+#    #+#             */
/*   Updated: 2024/02/05 18:27:04 by jovicto2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_min_value(t_stack *a, size_t stack_size)
{
	int		min;
	t_node	*temp_node;

	min = a->top->value;
	temp_node = a->top;
	while (stack_size--)
	{
		if (temp_node->value < min)
			min = temp_node->value;
		temp_node = temp_node->prev;
	}
	return (min);
}

int	get_max_value(t_stack *a, size_t stack_size)
{
	int		max;
	t_node	*temp_node;

	max = a->top->value;
	temp_node = a->top;
	while (stack_size--)
	{
		if (temp_node->value > max)
			max = temp_node->value;
		temp_node = temp_node->prev;
	}
	return (max);
}
