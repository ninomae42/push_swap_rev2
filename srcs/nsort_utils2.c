#include "push_swap.h"

size_t	get_insert_costs_from_top(t_dstack *stack, int value)
{
	size_t	costs;
	t_dnode	*nil;
	t_dnode	*current;

	costs = 0;
	nil = stack->nil;
	current = nil->next->next;
	while (current != NULL && current != nil)
	{
		if (current->num < value && value < current->prev->num)
			break ;
		costs++;
		current = current->next;
	}
	return (costs);
}

size_t	get_insert_costs_from_bottom(t_dstack *stack, int value)
{
	size_t	costs;
	t_dnode	*nil;
	t_dnode	*current;

	costs = 0;
	nil = stack->nil;
	current = nil->prev->prev;
	while (current != NULL && current != nil)
	{
		if (current->next->num < value && value < current->num)
			break ;
		costs++;
		current = current->prev;
	}
	return (costs);
}

size_t	get_costs_from_top(t_dstack *stack, int key)
{
	t_dnode	*nil;
	t_dnode	*current;
	size_t	costs;

	costs = 0;
	nil = stack->nil;
	current = nil->next;
	while (current != NULL && current != nil)
	{
		if (current->num == key)
			return (costs);
		costs++;
		current = current->next;
	}
	return (costs);
}

size_t	get_costs_from_bottom(t_dstack *stack, int key)
{
	t_dnode	*nil;
	t_dnode	*current;
	size_t	costs;

	costs = 1;
	nil = stack->nil;
	current = nil->prev;
	while (current != NULL && current != nil)
	{
		if (current->num == key)
			return (costs);
		costs++;
		current = current->prev;
	}
	return (costs);
}
