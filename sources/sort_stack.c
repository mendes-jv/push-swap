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

void	sort_stack(size_t stack_size, t_stack *a, t_stack *b, size_t iterations)
{
	size_t			push_rotate_count;
	t_sort_values	values;

	if (stack_size <= 3)
		three_or_less_sort();
	else if (stack_size == 5)
		five_sort();
	else
	{
		values = (t_sort_values){0, 0, 0, 0};
		select_pivots(stack_size, a, &values);
		push_rotate_count = stack_size;
		while (push_rotate_count++ < stack_size)
			push_rotate(a, b, &values);
		if (values.rotate_a > values.rotate_b)
			back_to_orig_ra(a, b, &values);
		else
			back_to_orig_rb(a, b, &values);
		sort_stack(values.rotate_a, a, b, iterations);
		push_back_to_stack(values.rotate_b, a, b, iterations);
		push_back_to_stack(values.push_b - values.rotate_b, a, b, iterations);
	}

}