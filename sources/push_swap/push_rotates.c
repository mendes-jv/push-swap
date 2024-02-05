/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotates.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:16:19 by jovicto2          #+#    #+#             */
/*   Updated: 2024/02/05 18:16:22 by jovicto2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_rotate_a(t_stack *a, t_stack *b, t_sort_values *values)
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

void	push_rotate_b(t_stack *a, t_stack *b, t_sort_values *values)
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
