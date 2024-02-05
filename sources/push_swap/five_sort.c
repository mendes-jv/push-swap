/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:09:38 by jovicto2          #+#    #+#             */
/*   Updated: 2024/02/05 18:09:43 by jovicto2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	five_sort_a(t_stack *a, t_stack *b);
static void	five_sort_b(t_stack *a, t_stack *b);
static int	get_median_value(t_stack *stack);

void	five_sort(t_stack *a, t_stack *b, t_byte priority_stack)
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
	size_t	size;

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
