#include "push_swap.h"

bool	is_gte_key_and_lte_key_exist(t_dstack *stack, int k_min, int k_max)
{
	t_dnode	*nil;
	t_dnode	*current;

	nil = stack->nil;
	current = nil->next;
	while (current != NULL && current != nil)
	{
		if (k_min <= current->num && current->num <= k_max)
			return (true);
		current = current->next;
	}
	return (false);
}

int	get_dstack_max(t_dstack *stack)
{
	t_dnode	*nil;
	t_dnode	*current;
	int		max;

	max = 0;
	nil = stack->nil;
	current = nil->next;
	while (current != NULL && current != nil)
	{
		if (max < current->num)
			max = current->num;
		current = current->next;
	}
	return (max);
}

size_t	get_steps_to_key_from_top(t_dstack *stack, int key)
{
	t_dnode	*nil;
	t_dnode	*current;
	size_t	steps;

	steps = 0;
	nil = stack->nil;
	current = nil->next;
	while (current != NULL && current != nil)
	{
		if (current->num == key)
			return (steps);
		steps++;
		current = current->next;
	}
	return (steps);
}

size_t	get_steps_to_key_from_bottom(t_dstack *stack, int key)
{
	t_dnode	*nil;
	t_dnode	*current;
	size_t	steps;

	steps = 1;
	nil = stack->nil;
	current = nil->prev;
	while (current != NULL && current != nil)
	{
		if (current->num == key)
			return (steps);
		steps++;
		current = current->prev;
	}
	return (steps);
}
