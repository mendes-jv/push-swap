/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:52:01 by jovicto2          #+#    #+#             */
/*   Updated: 2024/01/13 15:52:03 by jovicto2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/push_swap.h"
//
//static size_t	get_median_value(t_stack *a);
//
//void	five_or_less_values_stack_sort(t_stack *a, t_stack *b)
//{
//	size_t	push_b_count;
//	size_t	median_value;
//
//	push_b_count = 0;
//	median_value = get_median_value(a);
//	while (push_b_count != 2)
//	{
//		if (a->top->value < median_value)
//		{
//			apply_move(a, b, (t_move_stack)push, B);
//			push_b_count++;
//		}
//		else
//			apply_move(a, b, rotate, A);
//	}
//	three_or_less_values_stack_sort(a, b);
//	two_values_stack_sort(a, b);
//}
//
//static size_t	get_median_value(t_stack *a)
//{
//	int		index;
//	int		median_value;
//	int		*stack_values;
//	t_node	*temp_node;
//
//	index = 0;
//	stack_values = malloc(sizeof(int) * a->size);
//	temp_node = a->bottom;
//	while (index < a->size)
//	{
//		stack_values[index++] = a->top->value;
//		temp_node = temp_node->next;
//	}
//	median_value = stack_values[a->size / 2];
//	if (!(a->size % 2))
//		median_value = (median_value + stack_values[(a->size / 2) - 1]) / 2;
//	free(stack_values);
//	return (median_value);
//}
//
//static void three_or_less_values_stack_sort(t_stack *a, t_stack *b)
//{}
//
//static void two_values_stack_sort(t_stack *a, t_stack *b)
//{}