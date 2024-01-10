#include "../includes/push_swap.h"

void	small_stack_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 5)
		sort_five(a, b);
}

void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		apply_move()
}