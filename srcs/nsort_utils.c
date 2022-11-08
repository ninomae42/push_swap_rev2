#include "push_swap.h"

void	print_stack(t_cont *cont)
{
	printf("stackA");
	dstack_print(cont->stack_a);
	puts("");
	printf("stackB");
	dstack_print(cont->stack_b);
	puts("");
}

int		get_max(t_dstack *stack)
{
	int		max;
	t_dnode	*nil;
	t_dnode	*current;

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

int	get_min(t_dstack *stack)
{
	int		min;
	t_dnode	*nil;
	t_dnode	*current;

	min = INT_MAX;
	nil = stack->nil;
	current = nil->next;
	while (current != NULL && current != nil)
	{
		if (current->num < min)
			min = current->num;
		current = current->next;
	}
	return (min);
}
