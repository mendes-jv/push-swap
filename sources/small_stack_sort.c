#include "../includes/push_swap.h"

static size_t	get_median_value(t_stack *a);

void	small_stack_sort(t_stack *a, t_stack *b)
{
//	if (a->top->value > a->top->next->value)
//		apply_move(a, b, swap, AB);
	size_t	push_b_count;
	size_t	median_value;

	push_b_count = 0;
	median_value = get_median_value(a);
	while (push_b_count != 2)
	{
		if (a->top->value < )
			apply_move(a, b, (t_move_stack)push, B);
		else
			apply_move(a, b, rotate, A);
	}
}

static size_t	get_median_value(t_stack *a)
{
	size_t	index;
	t_node	*temp_node;
	int		median_value;
	int		bigger_values_count;

	temp_node = a->bottom;
	index = 0;
	while (bigger_values_count < a->size / 2)
	{
		if (temp_node->value > median_value)
			bigger_values_count++;
		temp_node = temp_node->next;
		index++;
	}
	while (index <= a->size && temp_node->next)
	{
		 = temp_node->value;
		temp_node = temp_node->next;
	}
	median_value = temp_node->value;
	return (median_value);
}