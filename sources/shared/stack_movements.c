/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:53:10 by jovicto2          #+#    #+#             */
/*   Updated: 2024/02/05 18:53:13 by jovicto2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_stack *a, t_stack *b)
{
	t_node	*temp_node;

	if (!a->size)
		return ;
	temp_node = a->top;
	a->top = a->top->prev;
	if (!a->top)
		a->bottom = NULL;
	else
		a->top->next = NULL;
	a->size--;
	if (!b->size)
	{
		temp_node->prev = NULL;
		b->top = temp_node;
		b->bottom = temp_node;
		b->size++;
		return ;
	}
	temp_node->prev = b->top;
	b->top->next = temp_node;
	b->top = temp_node;
	b->size++;
}

void	swap(t_stack *a)
{
	int	temp_value;

	if (a->size < 2)
		return ;
	temp_value = a->top->value;
	a->top->value = a->top->prev->value;
	a->top->prev->value = temp_value;
}

void	reverse_rotate(t_stack *a)
{
	int		bottom_value;
	t_node	*temp_node;

	if (a->size < 2)
		return ;
	temp_node = a->bottom;
	bottom_value = a->bottom->value;
	while (temp_node->next)
	{
		temp_node->value = temp_node->next->value;
		temp_node = temp_node->next;
	}
	a->top->value = bottom_value;
}

void	rotate(t_stack *a)
{
	int		top_value;
	t_node	*temp_node;

	if (a->size < 2)
		return ;
	temp_node = a->top;
	top_value = a->top->value;
	while (temp_node->prev)
	{
		temp_node->value = temp_node->prev->value;
		temp_node = temp_node->prev;
	}
	a->bottom->value = top_value;
}
