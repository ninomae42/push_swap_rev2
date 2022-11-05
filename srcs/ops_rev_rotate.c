#include "push_swap.h"

// argument stack guaranteed not to be NULL
static void	reverse_rotate(t_dstack *stack)
{
	t_dnode	*nil;
	t_dnode	*first_node;
	t_dnode	*last_node;

	nil = stack->nil;
	first_node = nil->next;
	last_node = nil->prev;
	nil->prev = last_node->prev;
	last_node->prev->next = nil;
	last_node->prev = nil;
	nil->next = last_node;
	last_node->next = first_node;
	first_node->prev = last_node;
}

// Shift down all elements of stack A by 1.
// The last element becomes the first one.
void	reverse_rotate_a(t_dstack *stack_a, t_ops *ops)
{
	if (stack_a == NULL || ops == NULL)
		return ;
	if (stack_a->size < 2)
		return ;
	reverse_rotate(stack_a);
	ops_push_back(ops, rra);
}

// Shift down all elements of stack B by 1.
// The last element becomes the first one.
void	reverse_rotate_b(t_dstack *stack_b, t_ops *ops)
{
	if (stack_b == NULL || ops == NULL)
		return ;
	if (stack_b->size < 2)
		return ;
	reverse_rotate(stack_b);
	ops_push_back(ops, rrb);
}

// reverse_rotate_a and reverse_rotate_b at the same time.
void	reverse_rotate_same(t_dstack *stack_a, t_dstack *stack_b, t_ops *ops)
{
	if (stack_a == NULL || stack_b == NULL || ops == NULL)
		return ;
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ops_push_back(ops, rrr);
}
