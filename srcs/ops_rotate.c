#include "push_swap.h"

// argument stack guaranteed not be NULL
static void	rotate(t_dstack *stack)
{
	t_dnode	*nil;
	t_dnode	*first_node;
	t_dnode	*last_node;

	nil = stack->nil;
	first_node = nil->next;
	last_node = nil->prev;
	nil->next = first_node->next;
	first_node->next->prev = nil;
	nil->prev = first_node;
	first_node->next = nil;
	first_node->prev = last_node;
	last_node->next = first_node;
}

// Shift up all elements of stack A by 1. 
// The first element becomes the last one.
void	rotate_a(t_dstack *stack_a, t_ops *ops)
{
	if (stack_a == NULL || ops == NULL)
		return ;
	if (stack_a->size < 2)
		return ;
	rotate(stack_a);
	ops_push_back(ops, ra);
}

// Shift up all elements of stack B by 1. 
// The first element becomes the last one.
void	rotate_b(t_dstack *stack_b, t_ops *ops)
{
	if (stack_b == NULL || ops == NULL)
		return ;
	if (stack_b->size < 2)
		return ;
	rotate(stack_b);
	ops_push_back(ops, rb);
}

// rotate_a and rotate_b at the same time.
void	rotate_same(t_dstack *stack_a, t_dstack *stack_b, t_ops *ops)
{
	if (stack_a == NULL || stack_b == NULL || ops == NULL)
		return ;
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	ops_push_back(ops, rr);
}
