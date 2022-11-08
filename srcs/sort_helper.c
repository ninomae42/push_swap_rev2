#include "push_swap.h"

// find the maximum value on given stack
size_t	get_max(t_dstack *stack)
{
	t_dnode	*nil;
	t_dnode	*current;
	size_t	max;

	nil = stack->nil;
	current = nil->next;
	max = 0;
	while (current != NULL && current != nil)
	{
		if (max < current->num)
			max = current->num;
		current = current->next;
	}
	return (max);
}

// find the minimum value on given stack
size_t	get_min(t_dstack *stack)
{
	t_dnode	*nil;
	t_dnode	*current;
	size_t	min;

	nil = stack->nil;
	current = nil->next;
	min = 0;
	while (current != NULL && current != nil)
	{
		if (current->num < min)
			min = current->num;
		current = current->next;
	}
	return (min);
}
