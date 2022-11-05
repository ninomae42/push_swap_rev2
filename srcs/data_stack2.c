#include "push_swap.h"

int	dstack_peek(t_dstack *stack)
{
	t_dnode	*nil;

	if (stack == NULL || stack->nil == NULL)
		return (0);
	nil = stack->nil;
	if (stack->size < 1)
		return (0);
	return (nil->next->num);
}

void	dstack_erace(t_dstack *stack, t_dnode *node)
{
	t_dnode	*prev_node;
	t_dnode	*next_node;
	t_dnode	*nil;

	if (stack == NULL || node == NULL || stack->size == 0)
		return ;
	nil = stack->nil;
	if (node == nil)
	{
		free(nil);
		return ;
	}
	prev_node = node->prev;
	next_node = node->next;
	prev_node->next = node->next;
	next_node->prev = node->prev;
	free(node);
	stack->size -= 1;
}

void	dstack_pop_front(t_dstack *stack)
{
	t_dnode	*nil;

	if (stack == NULL || stack->nil == NULL)
		return ;
	nil = stack->nil;
	if (0 < stack->size)
		dstack_erace(stack, nil->next);
}

void	dstack_clear(t_dstack *stack)
{
	t_dnode	*nil;
	t_dnode	*current;
	t_dnode	*tmp;

	if (stack == NULL || stack->nil == NULL || stack->size == 0)
		return ;
	nil = stack->nil;
	current = nil->next;
	while (current != NULL && current != nil)
	{
		tmp = current;
		current = current->next;
		dstack_erace(stack, tmp);
	}
	nil->next = nil;
	nil->prev = nil;
}

t_dstack	*dstack_copy(t_dstack *stack)
{
	t_dstack	*copy;
	t_dnode		*nil;
	t_dnode		*current;

	if (stack == NULL || stack->nil == NULL)
		return (NULL);
	copy = dstack_init();
	nil = stack->nil;
	current = nil->next;
	while (current != NULL && current != nil)
	{
		dstack_push_back(copy, current->num);
		current = current->next;
	}
	return (copy);
}
