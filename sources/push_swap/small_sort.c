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

void	small_sort(size_t size, t_stack *a, t_stack *b, t_byte stack)
{
	if (size == 3)
		three_sort(a, b, stack);
	else if (size == 2)
		two_sort(a, b, stack);
	else if (size == 1 && stack == B)
		apply_move(a, b, push, A);
}

void	three_sort(t_stack *a, t_stack *b, t_byte s)
{
	int		min;
	int		max;
	t_stack	*stack;

	if (s == A)
		stack = a;
	else
		stack = b;
	min = get_min_value(stack, 3);
	max = get_max_value(stack, 3);
	if ((s == A && a->top->value == min) || (s == B && b->top->value == min))
		top_min_sort(a, b, s, max);
	else if ((s == A && a->top->prev->value == min)
		|| (s == B && b->top->prev->value == min))
		mid_min_sort(a, b, s, max);
	else
		bot_min_sort(a, b, s, max);
	if (s == B)
	{
		apply_move(a, b, push, A);
		apply_move(a, b, push, A);
		apply_move(a, b, push, A);
	}
}

void	two_sort(t_stack *a, t_stack *b, t_byte stack)
{
	if (stack == A && a->top->value > a->top->prev->value)
		apply_move(a, b, swap, A);
	else if (stack == B)
	{
		if (b->top->value < b->top->prev->value)
			apply_move(a, b, swap, B);
		apply_move(a, b, push, A);
		apply_move(a, b, push, A);
	}
}
