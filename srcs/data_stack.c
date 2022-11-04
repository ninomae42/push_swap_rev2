#include "push_swap.h"

t_dnode	*dnode_new(int num)
{
	t_dnode	*new;

	new = (t_dnode *)malloc_or_exit(sizeof(t_dnode));
	if (new == NULL)
		return (NULL);
	new->num = num;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_dstack	*dstack_init(void)
{
	t_dstack	*stack;

	stack = (t_dstack *)malloc_or_exit(sizeof(t_dstack));
	stack->nil = dnode_new(0);
	stack->size = 0;
	stack->nil->next = stack->nil;
	stack->nil->prev = stack->nil;
	return (stack);
}

void	dstack_push_front(t_dstack *stack, int num)
{
	t_dnode	*nil;
	t_dnode	*new;

	if (stack == NULL || stack->nil == NULL)
		return ;
	nil = stack->nil;
	new = dnode_new(num);
	if (stack->size == 0)
	{
		nil->next = new;
		nil->prev = new;
		new->prev = nil;
		new->next = nil;
	}
	else
	{
		new->next = nil->next;
		nil->next->prev = new;
		nil->next = new;
		new->prev = nil;
	}
	stack->size += 1;
}

void	dstack_push_back(t_dstack *stack, int num)
{
	t_dnode	*nil;
	t_dnode	*new;

	if (stack == NULL || stack->nil == NULL)
		return ;
	nil = stack->nil;
	new = dnode_new(num);
	if (stack->size == 0)
	{
		nil->next = new;
		nil->prev = new;
		new->prev = nil;
		new->next = nil;
	}
	else
	{
		new->next = nil;
		new->prev = nil->prev;
		nil->prev->next = new;
		nil->prev = new;
	}
	stack->size += 1;
}

void	dstack_print(t_dstack *stack)
{
	t_dnode	*nil;
	t_dnode	*current;

	if (stack == NULL || stack->size == 0 || stack->nil == NULL)
		return ;
	nil = stack->nil;
	current = nil->next;
	printf("Current stack(n = %zu): ", stack->size);
	while (current != NULL && current != nil)
	{
		printf("%d ", current->num);
		current = current->next;
	}
	puts("");
}
