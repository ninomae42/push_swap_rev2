#include "push_swap.h"

// Take the first element at the top pf B and put it at the top of A.
// Do nothing if B is empty.
void	push_a(t_dstack *stack_a, t_dstack *stack_b, t_ops *ops)
{
	int	tmp;

	if (stack_a == NULL || stack_b == NULL || ops == NULL)
		return ;
	if (stack_b->size == 0)
		return ;
	tmp = dstack_peek(stack_b);
	dstack_pop_front(stack_b);
	dstack_push_front(stack_a, tmp);
	ops_push_back(ops, pa);
}

// Take the first element at the top pf A and put it at the top of B.
// Do nothing if A is empty.
void	push_b(t_dstack *stack_a, t_dstack *stack_b, t_ops *ops)
{
	int	tmp;

	if (stack_a == NULL || stack_b == NULL || ops == NULL)
		return ;
	if (stack_a->size == 0)
		return ;
	tmp = dstack_peek(stack_a);
	dstack_pop_front(stack_a);
	dstack_push_front(stack_b, tmp);
	ops_push_back(ops, pb);
}
