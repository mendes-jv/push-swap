#include "../includes/push_swap.h"

static void	print_moves(t_one_stack move, char stacks);

void	apply_move(t_stack *a, t_stack *b, t_one_stack move, char stacks)
{
	if ((t_double_stacks)move == push)
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

static void	print_moves(t_one_stack move, char stacks)
{
	char	*log_move;

	if ((t_double_stacks)move == push)
		log_move = "p";
	else if (move == swap)
		log_move = "s";
	else if (move == rotate)
		log_move = "r";
	else
		log_move = "rr";
	ft_putstr_fd(log_move, STDOUT_FILENO);
	if (stacks == A)
		ft_putstr_fd("a", STDOUT_FILENO);
	else if (stacks == B)
		ft_putstr_fd("b", STDOUT_FILENO);
	else
		write(STDOUT_FILENO,log_move, sizeof(char));
	write(STDOUT_FILENO,"\n", sizeof(char));
}