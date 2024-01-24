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
static void	select_pivots(size_t stack_size, t_stack *a, t_sort_values *values);
static int	get_min_value(t_stack *a, size_t stack_size);
static int	get_max_value(t_stack *a, size_t stack_size);
static void	back_to_orig_rotate(t_stack *a, t_stack *b, size_t iterations, t_sort_values *values);
static void push_back_to_stack(size_t stack_size, t_stack *a, t_stack *b, size_t iterations);
static void	push_rotate(t_stack *a, t_stack *b, t_sort_values *values);
static void	three_or_less_sort(t_stack *a, t_stack *b, t_byte priority_stack);
static void	two_sort(t_stack *a, t_stack *b, t_byte priority_stack);
static void	three_sort(t_stack *a, t_stack *b, t_byte priority_stack);
static void	five_sort(t_stack *a, t_stack *b);
static int	get_median_value(t_stack *a);

void	sort_stack(size_t stack_size, t_stack *a, t_stack *b, size_t iterations)
{
	size_t			push_rotate_count;
	t_sort_values	values;

	if (stack_size <= 3)
		three_or_less_sort(a, b, A);
	else if (stack_size == 5)
		five_sort(a, b);
	else
	{
		values = (t_sort_values){0, 0, 0, 0, 0 ,0};
		select_pivots(stack_size, a, &values);
		push_rotate_count = stack_size;
		while (push_rotate_count++ < stack_size)
			push_rotate(a, b, &values);
		back_to_orig_rotate(a, b, iterations, &values);
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
		three_or_less_sort(a, b, A);
	else if (stack_size == 5)
		five_sort(a, b);
	else
	{
		values = (t_sort_values){0, 0, 0, 0, 0 ,0};
		select_pivots(stack_size, a, &values);
		push_rotate_count = stack_size;
		while (push_rotate_count++ < stack_size)
			push_rotate(a, b, &values);
		sort_stack(values.push_a - values.rotate_a, a, b, iterations);
		back_to_orig_rotate(a, b, iterations, &values);
		sort_stack(values.rotate_a, a, b, iterations);
		sort_stack(values.rotate_b, a, b, iterations);
		push_back_to_stack(values.push_b - values.rotate_b, a, b, iterations);
	}
}

static void	select_pivots(size_t stack_size, t_stack *a, t_sort_values *values)
{
	int	min;
	int	max;

	min = get_min_value(a, stack_size);
	max = get_max_value(a, stack_size);
	values->big_pivot = (min + max) / 2;
	values->small_pivot = (min + max) / 2;
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

static void	back_to_orig_rotate(t_stack *a, t_stack *b, size_t iterations, t_sort_values *values)
{
	size_t rotate_both_count = ft_operate(values->rotate_a, values->rotate_b, MIN);
	size_t rotate_a_remaining_count = values->rotate_a - rotate_both_count;
	size_t rotate_b_remaining_count = values->rotate_b - rotate_both_count;

	if (iterations > 0) {
		while (rotate_both_count--)
			apply_move(a, b, rotate, AB);
		while (rotate_a_remaining_count--)
			apply_move(a, b, rotate, A);
		while (rotate_b_remaining_count--)
			apply_move(a, b, rotate, B);
		return;
	}

	rotate_b_remaining_count = ft_operate(values->rotate_a, values->rotate_b, MAX);
	while (rotate_b_remaining_count--)
		apply_move(a, b, rotate, B);
}

static void	push_rotate(t_stack *a, t_stack *b, t_sort_values *values)
{
	if (a->top->value >= values->big_pivot)
	{
		apply_move(a, b, push, B);
		values->push_b++;
		if (b->top->value >= values->small_pivot)
		{
			apply_move(a, b, rotate, B);
			values->rotate_b++;
		}
	}
	else
	{
		apply_move(a, b, rotate, A);
		values->rotate_a++;
	}
}

static void	three_or_less_sort(t_stack *a, t_stack *b, t_byte priority_stack)
{
	if (a->size == 1 && priority_stack == B)
		apply_move(a, b, push, B);
	else if (a->size == 2)
		two_sort(a, b, priority_stack);
	else if (a->size == 3)
		three_sort(a, b, priority_stack);
}

static void	two_sort(t_stack *a, t_stack *b, t_byte priority_stack)
{
	if (priority_stack == A && a->top->value > a->top->next->value)
		apply_move(a, b, swap, A);
	else if (priority_stack == B) {
		if (b->top->value < b->top->next->value)
			apply_move(a, b, swap, B);
		apply_move(a, b, push, A);
		apply_move(a, b, push, A);
	}
}

static void	three_sort(t_stack *a, t_stack *b, t_byte priority_stack)
{
	if (priority_stack == A)
	{
		if (a->top->value > a->top->next->value
			&& a->top->value > a->top->next->next->value)
			apply_move(a, b, rotate, A);
		else if (a->top->next->value > a->top->value
			&& a->top->next->value > a->top->next->next->value)
			apply_move(a, b, reverse_rotate, A);
	}
	else
	{
		if (a->top->value < a->top->next->value
			&& a->top->value < a->top->next->next->value)
			apply_move(a, b, rotate, A);
		else if (a->top->next->value < a->top->value
			&& a->top->next->value < a->top->next->next->value)
			apply_move(a, b, reverse_rotate, A);
	}
	if (priority_stack == B)
		apply_move(a, b, push, B);
}

static void	five_sort(t_stack *a, t_stack *b)
{
	size_t	push_b_count;
	int		median_value;

	push_b_count = 0;
	median_value = get_median_value(a);
	while (push_b_count != 2)
	{
		if (a->top->value < median_value)
		{
			apply_move(a, b, push, B);
			push_b_count++;
		}
		else
			apply_move(a, b, rotate, A);
	}
	three_or_less_sort(a, b, A);
	two_sort(a, b, A);
}

static int	get_median_value(t_stack *a)
{
	size_t	index;
	int		median_value;
	int		*stack_values;
	t_node	*temp_node;

	index = 0;
	stack_values = malloc(sizeof(int) * a->size);
	temp_node = a->bottom;
	while (index < a->size)
	{
		stack_values[index++] = a->top->value;
		temp_node = temp_node->next;
	}
	median_value = stack_values[a->size / 2];
	if (!(a->size % 2))
		median_value = (median_value + stack_values[(a->size / 2) - 1]) / 2;
	free(stack_values);
	return (median_value);
}