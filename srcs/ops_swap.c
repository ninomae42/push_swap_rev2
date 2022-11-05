#include "push_swap.h"

// argument stack Must not be NULL value.
static void	swap(t_dstack *stack)
{
	t_dnode	*first;
	int		tmp;

	first = stack->nil->next;
	tmp = first->num;
	first->num = first->next->num;
	first->next->num = tmp;
}

// Swap the first 2 elements at the top of stack A.
// Do nothing if there is only one or no elements.
void	swap_a(t_dstack *stack_a, t_ops *ops)
{
	if (stack_a == NULL || ops == NULL || stack_a->size < 2)
		return ;
	swap(stack_a);
	ops_push_back(ops, sa);
}

// Swap the first 2 elements at the top of stack B.
// Do nothing if there is only one or no elements.
void	swap_b(t_dstack *stack_b, t_ops *ops)
{
	if (stack_b == NULL || ops == NULL || stack_b->size < 2)
		return ;
	swap(stack_b);
	ops_push_back(ops, sb);
}

// swap_a and swap_b at the same time.
void	swap_same(t_dstack *stack_a, t_dstack *stack_b, t_ops *ops)
{
	if (stack_a == NULL || stack_b == NULL || ops == NULL)
		return ;
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	swap(stack_a);
	swap(stack_b);
	ops_push_back(ops, ss);
}
