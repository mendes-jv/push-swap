/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:00:40 by jovicto2          #+#    #+#             */
/*   Updated: 2023/12/11 11:00:41 by jovicto2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	handle_move(t_stack *a, t_stack *b, char *line);
static void	handle_swaps(t_stack *a, t_stack *b, char *move);
static void	handle_pushes(t_stack *a, t_stack *b, const char *move);
static void	handle_rotations(t_stack *a, t_stack *b, char *move);

void	read_moves(t_stack *a, t_stack *b)
{
	char	*line;

	line = ft_get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strchr(line, ' '))
		{
			free(line);
			free_nodes(a->top);
			free_nodes(b->top);
			ft_handle_error(ERROR_MESSAGE);
		}
		handle_move(a, b, line);
		free(line);
		line = ft_get_next_line(STDIN_FILENO);
	}
}

static void	handle_move(t_stack *a, t_stack *b, char *line)
{
	char	*move;

	move = ft_strtrim(line, "\n");
	if (ft_strnstr(SWAPS, move, ft_strlen(SWAPS)))
		handle_swaps(a, b, move + 1);
	else if (ft_strnstr(PUSHES, move, ft_strlen(PUSHES)))
		handle_pushes(a, b, move + 1);
	else if (ft_strnstr(ROTATIONS, move, ft_strlen(ROTATIONS)))
		handle_rotations(a, b, move + 1);
	else
	{
		free(move);
		free(line);
		free_nodes(a->top);
		free_nodes(b->top);
		ft_handle_error(ERROR_MESSAGE);
	}
	free(move);
}

static void	handle_swaps(t_stack *a, t_stack *b, char *move)
{
	if (ft_strnstr("sa", move, 2))
		swap(a);
	if (ft_strnstr("sb", move, 2))
		swap(b);
}

static void	handle_pushes(t_stack *a, t_stack *b, const char *move)
{
	if (*move == 'a')
		push(b, a);
	else
		push(a, b);
}

static void	handle_rotations(t_stack *a, t_stack *b, char *move)
{
	if (ft_strlen(move) >= 2)
	{
		if (ft_strnstr("ra", move + 1, 2))
			reverse_rotate(a);
		if (ft_strnstr("rb", move + 1, 2))
			reverse_rotate(b);
	}
	else
	{
		if (ft_strnstr("ra", move, 2))
			rotate(a);
		if (ft_strnstr("rb", move, 2))
			rotate(b);
	}
}
