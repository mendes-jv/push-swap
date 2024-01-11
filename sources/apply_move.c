#include "../includes/push_swap.h"

static void	print_moves(void *move, t_byte stacks);

void	apply_move(t_stack *a, t_stack *b, t_move_stack move, t_byte stacks)
{
	if ((t_push_stack)move == push)
	{
		if (stacks == A)
			push(a, b);
		else
			push(b, a);
	}
	else
	{
		if (stacks & A)
			move(a);
		if (stacks & B)
			move(b);
	}
	print_moves(move, stacks);
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
		write(STDOUT_FILENO, move_abbreviation, sizeof(char));
	write(STDOUT_FILENO,"\n", sizeof(char));
}