/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:57:14 by jovicto2          #+#    #+#             */
/*   Updated: 2024/02/05 18:57:17 by jovicto2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static bool	check_stacks(t_stack *a, t_stack *b, void *move, t_byte stacks);
static void	print_moves(void *move, t_byte stacks);

void	apply_move(t_stack *a, t_stack *b, void *move, t_byte stacks)
{
	if (check_stacks(a, b, move, stacks))
		return ;
	if (move == push)
	{
		if (stacks == B)
			push(a, b);
		else
			push(b, a);
	}
	else
	{
		if (stacks & A)
			((t_move_stack)move)(a);
		if (stacks & B)
			((t_move_stack)move)(b);
	}
	print_moves(move, stacks);
}

static bool	check_stacks(t_stack *a, t_stack *b, void *move, t_byte stacks)
{
	return (((move == push) && ((stacks == A && b->size < 1)
		|| (stacks == B && a->size < 1)))
		|| ((move != push) && ((stacks == A && a->size <= 1)
		|| (stacks == B && b->size <= 1))));
}

static void	print_moves(void *move, t_byte stacks)
{
	char	*move_abbreviation;

	if (move == push)
		move_abbreviation = "p";
	else if (move == swap)
		move_abbreviation = "s";
	else if (move == rotate)
		move_abbreviation = "r";
	else
		move_abbreviation = "rr";
	ft_putstr_fd(move_abbreviation, STDOUT_FILENO);
	if (stacks == A)
		ft_putstr_fd("a", STDOUT_FILENO);
	else if (stacks == B)
		ft_putstr_fd("b", STDOUT_FILENO);
	else
		ft_putchar_fd(*move_abbreviation, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
