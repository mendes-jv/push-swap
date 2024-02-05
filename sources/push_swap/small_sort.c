/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:20:54 by jovicto2          #+#    #+#             */
/*   Updated: 2024/02/05 18:20:57 by jovicto2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	small_sort(size_t size, t_stack *a, t_stack *b, t_byte priority_stack)
{
	if (size == 3)
		three_sort(a, b, priority_stack);
	else if (size == 2)
		two_sort(a, b, priority_stack);
	else if (size == 1 && priority_stack == B)
		apply_move(a, b, push, A);
}

void	three_sort(t_stack *a, t_stack *b, t_byte priority_stack)
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
		top_min_sort(a, b, priority_stack, max);
	else if (a->top->prev->value == min)
		mid_min_sort(a, b, priority_stack, max);
	else
		bot_min_sort(a, b, priority_stack, max);
	if (priority_stack == B)
	{
		apply_move(a, b, push, A);
		apply_move(a, b, push, A);
		apply_move(a, b, push, A);
	}
}

void	two_sort(t_stack *a, t_stack *b, t_byte priority_stack)
{
	if (priority_stack == A && a->top->value > a->top->prev->value)
		apply_move(a, b, swap, A);
	else if (priority_stack == B)
	{
		if (b->top->value < b->top->prev->value)
			apply_move(a, b, swap, B);
		apply_move(a, b, push, A);
		apply_move(a, b, push, A);
	}
}
