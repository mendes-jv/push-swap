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

#include "../../includes/push_swap.h"

static void	push_back(size_t size, t_stack *a, t_stack *b, size_t iterations);
static void	select_pivots(size_t stack_size, t_stack *a, t_values *values);

void	sort_stack(size_t stack_size, t_stack *a, t_stack *b, size_t iterations)
{
	size_t		push_rotate_count;
	t_values	values;

	if (stack_size <= 3)
		small_sort(stack_size, a, b, A);
	else if (stack_size == 5)
		five_sort(a, b, A);
	else
	{
		values = (t_values){0, 0, 0, 0, 0, 0};
		select_pivots(stack_size, a, &values);
		push_rotate_count = stack_size;
		while (push_rotate_count--)
			push_rotate_a(a, b, &values);
		reorder_rr(a, b, (t_rr){A, iterations}, &values);
		sort_stack(values.rotate_a, a, b, iterations);
		push_back(values.rotate_b, a, b, iterations);
		push_back(values.push_b - values.rotate_b, a, b, iterations);
	}
}

static void	push_back(size_t size, t_stack *a, t_stack *b, size_t iterations)
{
	size_t		push_rotate_count;
	t_values	values;

	iterations++;
	if (size <= 3)
		small_sort(size, a, b, B);
	else if (size == 5)
		five_sort(a, b, B);
	else
	{
		values = (t_values){0, 0, 0, 0, 0, 0};
		select_pivots(size, b, &values);
		push_rotate_count = size;
		while (push_rotate_count--)
			push_rotate_b(a, b, &values);
		sort_stack(values.push_a - values.rotate_a, a, b, iterations);
		reorder_rr(a, b, (t_rr){B, iterations}, &values);
		sort_stack(values.rotate_a, a, b, iterations);
		push_back(values.rotate_b, a, b, iterations);
	}
}

static void	select_pivots(size_t stack_size, t_stack *a, t_values *values)
{
	int	min;
	int	max;

	min = get_min_value(a, stack_size);
	max = get_max_value(a, stack_size);
	values->big_pivot = (min + max) / 2;
	values->small_pivot = (min + values->big_pivot) / 2;
}
