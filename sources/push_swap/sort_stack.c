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
static void	select_pivots(size_t stack_size, t_stack *a, t_sort_values *values);
static int	get_min_value(t_stack *a, size_t stack_size);
static int	get_max_value(t_stack *a, size_t stack_size);
static void	reverse_rotate_reorder(t_stack *a, t_stack *b, t_reorder params, t_sort_values *values);
static void push_back_to_stack(size_t stack_size, t_stack *a, t_stack *b, size_t iterations);
static void	push_rotate_a(t_stack *a, t_stack *b, t_sort_values *values);
static void	push_rotate_b(t_stack *a, t_stack *b, t_sort_values *values);
static void	three_or_less_sort(size_t stack_size, t_stack *a, t_stack *b, t_byte priority_stack);
static void	two_sort(t_stack *a, t_stack *b, t_byte priority_stack);
static void	three_sort(t_stack *a, t_stack *b, t_byte priority_stack);
static void	three_with_top_min_sort(t_stack *a, t_stack *b, t_byte priority_stack, int max);
static void	three_with_mid_min_sort(t_stack *a, t_stack *b, t_byte priority_stack, int max);
static void	three_with_bot_min_sort(t_stack *a, t_stack *b, t_byte priority_stack, int max);
static void	five_sort(t_stack *a, t_stack *b, t_byte priority_stack);
static void	five_sort_a(t_stack *a, t_stack *b);
static void	five_sort_b(t_stack *a, t_stack *b);
static int	get_median_value(t_stack *stack);

void	sort_stack(size_t stack_size, t_stack *a, t_stack *b, size_t iterations)
{
	size_t			push_rotate_count;
	t_sort_values	values;

	if (stack_size <= 3)
		three_or_less_sort(stack_size, a, b, A);
	else if (stack_size == 5)
		five_sort(a, b, A);
	else
	{
		values = (t_sort_values){0, 0, 0, 0, 0 ,0};
		select_pivots(stack_size, a, &values);
		push_rotate_count = stack_size;
		while (push_rotate_count--)
			push_rotate_a(a, b, &values);
		reverse_rotate_reorder(a, b, (t_reorder) {A, iterations}, &values);
		sort_stack(values.rotate_a, a, b, iterations);
		push_back_to_stack(values.rotate_b, a, b, iterations);
		push_back_to_stack(values.push_b - values.rotate_b, a, b, iterations);
	}
}

static void	push_back_to_stack(size_t stack_size, t_stack *a, t_stack *b, size_t iterations)
{
	size_t			push_rotate_count;
	t_sort_values	values;

	iterations++;
	if (stack_size <= 3)
		three_or_less_sort(stack_size, a, b, B);
	else if (stack_size == 5)
		five_sort(a, b, B);
	else
	{
		values = (t_sort_values){0, 0, 0, 0, 0 ,0};
		select_pivots(stack_size, b, &values);
		push_rotate_count = stack_size;
		while (push_rotate_count--)
			push_rotate_b(a, b, &values);
		sort_stack(values.push_a - values.rotate_a, a, b, iterations);
		reverse_rotate_reorder(a, b, (t_reorder) {B, iterations} , &values);
		sort_stack(values.rotate_a, a, b, iterations);
		push_back_to_stack(values.rotate_b, a, b, iterations);
	}
}

static void	select_pivots(size_t stack_size, t_stack *a, t_sort_values *values)
{
	int	min;
	int	max;

	min = get_min_value(a, stack_size);
	max = get_max_value(a, stack_size);
	values->big_pivot = (min + max) / 2;
	values->small_pivot = (min + values->big_pivot) / 2;
}

static int	get_min_value(t_stack *a, size_t stack_size)
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

static int	get_max_value(t_stack *a, size_t stack_size)
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

static void	reverse_rotate_reorder(t_stack *a, t_stack *b, t_reorder params, t_sort_values *values)
{
	size_t rotate_both_count = ft_operate(values->rotate_a, values->rotate_b, MIN);
	size_t rotate_a_remaining_count = values->rotate_a - rotate_both_count;
	size_t rotate_b_remaining_count = values->rotate_b - rotate_both_count;

	if (params.iterations > 0 || params.priority_stack == B) {
		while (rotate_both_count--)
			apply_move(a, b, reverse_rotate, AB);
		while (rotate_a_remaining_count--)
			apply_move(a, b, reverse_rotate, A);
		while (rotate_b_remaining_count--)
			apply_move(a, b, reverse_rotate, B);
		return;
	}
	rotate_b_remaining_count = ft_operate(rotate_both_count, values->rotate_b, MAX);
	while (rotate_b_remaining_count--)
		apply_move(a, b, reverse_rotate, B);
}

static void	push_rotate_a(t_stack *a, t_stack *b, t_sort_values *values)
{
	if (a->top->value > values->big_pivot)
	{
		apply_move(a, b, rotate, A);
		values->rotate_a++;
	}
	else
	{
		apply_move(a, b, push, B);
		values->push_b++;
		if (b->top->value > values->small_pivot)
		{
			apply_move(a, b, rotate, B);
			values->rotate_b++;
		}
	}
}

static void	push_rotate_b(t_stack *a, t_stack *b, t_sort_values *values)
{
	if (b->top->value <= values->small_pivot)
	{
		apply_move(a, b, rotate, B);
		values->rotate_b++;
	}
	else
	{
		apply_move(a, b, push, A);
		values->push_a++;
		if (a->top->value <= values->big_pivot)
		{
			apply_move(a, b, rotate, A);
			values->rotate_a++;
		}
	}
}

static void	three_or_less_sort(size_t stack_size, t_stack *a, t_stack *b, t_byte priority_stack)
{
	if (stack_size == 3)
		three_sort(a, b, priority_stack);
	else if (stack_size == 2)
		two_sort(a, b, priority_stack);
	else if (stack_size == 1 && priority_stack == B)
		apply_move(a, b, push, A);
}

static void	two_sort(t_stack *a, t_stack *b, t_byte priority_stack)
{
	if (priority_stack == A && a->top->value > a->top->prev->value)
		apply_move(a, b, swap, A);
	else if (priority_stack == B) {
		if (b->top->value < b->top->prev->value)
			apply_move(a, b, swap, B);
		apply_move(a, b, push, A);
		apply_move(a, b, push, A);
	}
}

static void	three_sort(t_stack *a, t_stack *b, t_byte priority_stack)
{
	int	min;
	int	max;

	if (priority_stack == A)
	{
		min = get_min_value(a, 3);
		max = get_max_value(a, 3);
	}
	else
	{
		min = get_min_value(b, 3);
		max = get_max_value(b, 3);
	}
	if (a->top->value == min)
		three_with_top_min_sort(a, b, priority_stack, max);
	else if (a->top->prev->value == min)
		three_with_mid_min_sort(a, b, priority_stack, max);
	else
		three_with_bot_min_sort(a, b, priority_stack, max);
	if (priority_stack == B)
	{
		apply_move(a, b, push, A);
		apply_move(a, b, push, A);
		apply_move(a, b, push, A);
	}
}

static void	three_with_top_min_sort(t_stack *a, t_stack *b, t_byte priority_stack, int max)
{
	if (priority_stack == A)
	{
		if (a->top->prev->value == max) {
			if (a->size <= 3) {
				apply_move(a, b, reverse_rotate, A);
				apply_move(a, b, swap, A);
			}
			else
			{
				apply_move(a, b, rotate, A);
				apply_move(a, b, swap, A);
				apply_move(a, b, reverse_rotate, A);
			}
		}
	}
	else {
		if (b->size <= 3)
			apply_move(a, b, rotate, B);
		else
		{
			apply_move(a, b, swap, B);
			apply_move(a, b, rotate, B);
			apply_move(a, b, swap, B);
			apply_move(a, b, reverse_rotate, B);
		}
		if (b->top->prev->value == max)
			apply_move(a, b, swap, B);
	}
}

static void	three_with_mid_min_sort(t_stack *a, t_stack *b, t_byte priority_stack, int max)
{
	if (priority_stack == A)
	{
		if (a->size <= 3)
		{
			if (a->bottom->value == max)
				apply_move(a, b, swap, A);
			else
				apply_move(a, b, rotate, A);
		}
		else
		{
			apply_move(a, b, swap, A);
			if (a->top->prev->value == max) {
				apply_move(a, b, rotate, A);
				apply_move(a, b, swap, A);
				apply_move(a, b, reverse_rotate, A);
			}
		}
	}
	else
	{
		if (b->size <= 3)
			apply_move(a, b, reverse_rotate, B);
		else
		{
			apply_move(a, b, rotate, B);
			apply_move(a, b, swap, B);
			apply_move(a, b, reverse_rotate, B);
		}
		if (b->top->prev->value == max)
			apply_move(a, b, swap, B);
	}
}

static void	three_with_bot_min_sort(t_stack *a, t_stack *b, t_byte priority_stack, int max)
{
	if (priority_stack == A)
	{
		if (a->top->value == max)
			apply_move(a, b, swap, A);
		if (a->size <= 3)
			apply_move(a, b, reverse_rotate, A);
		else
		{
			apply_move(a, b, rotate, A);
			apply_move(a, b, swap, A);
			apply_move(a, b, reverse_rotate, A);
			apply_move(a, b, swap, A);
		}
	}
	else if (b->top->prev->value == max)
		apply_move(a, b, swap, B);
}

static void	five_sort(t_stack *a, t_stack *b, t_byte priority_stack)
{
	if (priority_stack == A)
		five_sort_a(a, b);
	else
		five_sort_b(a, b);
	three_sort(a, b, A);
	two_sort(a, b, B);
}

static void	five_sort_a(t_stack *a, t_stack *b)
{
	int		mid;
	int		push_count;
	int		rotate_count;
	size_t 	size;

	push_count = 0;
	rotate_count = 0;
	size = 5;
	mid = get_median_value(a);
	while (size-- && push_count <= 2)
	{
		if (a->top->value < mid)
		{
			apply_move(a, b, push, B);
			push_count++;
		}
		else
		{
			apply_move(a, b, rotate, A);
			rotate_count++;
		}
	}
	while (rotate_count--)
		apply_move(a, b, reverse_rotate, A);
}

static void	five_sort_b(t_stack *a, t_stack *b)
{
	int		mid;
	int		push_count;
	int		rotate_count;
	size_t	size;

	push_count = 0;
	rotate_count = 0;
	size = 5;
	mid = get_median_value(b);
	while (size-- && push_count <= 3)
	{
		if (b->top->value >= mid)
		{
			apply_move(a, b, push, A);
			push_count++;
		}
		else
		{
			apply_move(a, b, rotate, B);
			rotate_count++;
		}
	}
	while (rotate_count--)
		apply_move(a, b, reverse_rotate, B);
}

static int	get_median_value(t_stack *stack)
{
	size_t	index;
	int		median_value;
	int		*stack_values;
	t_node	*temp_node;

	index = 0;
	stack_values = malloc(sizeof(int) * 5);
	temp_node = stack->top;
	while (index < 5)
	{
		stack_values[index++] = temp_node->value;
		temp_node = temp_node->prev;
	}
	index /= 2;
	ft_sort_int_arr(stack_values, 5);
	median_value = stack_values[index];
	free(stack_values);
	return (median_value);
}