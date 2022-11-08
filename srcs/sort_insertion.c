#include "push_swap.h"

size_t	get_insert_index_from_top(t_dstack *stack, int value)
{
	size_t	steps;
	t_dnode	*nil;
	t_dnode	*current;

	steps = 0;
	nil = stack->nil;
	current = nil->next->next;
	while (current != NULL && current != nil)
	{
		if (current->num < value && value < current->prev->num)
			break ;
		steps++;
		current = current->next;
	}
	return (steps);
}

size_t	get_insert_index_from_bottom(t_dstack *stack, int value)
{
	size_t	steps;
	t_dnode	*nil;
	t_dnode	*current;

	steps = 0;
	nil = stack->nil;
	current = nil->prev->prev;
	while (current != NULL && current != nil)
	{
		if (current->next->num < value && value < current->num)
			break ;
		steps++;
		current = current->prev;
	}
	return (steps);
}

void	rotate_push(t_cont *cont, size_t steps1, size_t steps2)
{
	if (steps1 < steps2)
		while (steps1--)
			rotate_b(cont->stack_b, cont->ops);
	else
		while (steps2--)
			reverse_rotate_b(cont->stack_b, cont->ops);
	push_b(cont->stack_a, cont->stack_b, cont->ops);
	print_stack(cont);
}

void	rotate_push2(t_cont *cont, size_t steps, bool is_reverse)
{
	if (is_reverse)
		while (steps--)
			reverse_rotate_b(cont->stack_b, cont->ops);
	else
		while (steps--)
			rotate_b(cont->stack_b, cont->ops);
	push_b(cont->stack_a, cont->stack_b, cont->ops);
	print_stack(cont);
}

void	calcurate_cost(t_cont *cont)
{
	size_t	steps1;
	size_t	steps2;
	bool	is_reverse;
	t_dnode	*current;
	size_t	base_cost;
	size_t	total_cost;
	size_t	prev_cost;
	int		lower_cost_number;

	current = cont->stack_a->nil->next;
	base_cost = 1;
	prev_cost = SIZE_T_MAX;
	lower_cost_number = INT_MAX;
	while (current != cont->stack_a->nil)
	{
		total_cost = 0;
		is_reverse = false;
		if (get_max(cont->stack_b) < current->num || current->num < get_min(cont->stack_b))
		{
			puts("max or min");
			steps1 = get_steps_to_key_from_top2(cont->stack_b, get_max(cont->stack_b));
			steps2 = get_steps_to_key_from_bottom2(cont->stack_b, get_max(cont->stack_b));
		}
		else
		{
			puts("normal");
			steps1 = get_insert_index_from_top(cont->stack_b, current->num);
			steps2 = get_insert_index_from_bottom(cont->stack_b, current->num);
		}
		if (steps1 > steps2)
		{
			is_reverse = true;
			total_cost = steps2;
		}
		else
			total_cost = steps1;
		printf("current: %d, steps1: %zu, steps2: %zu, reverse?: %d\n", current->num, steps1, steps2, is_reverse);
		total_cost += base_cost;
		if (total_cost < prev_cost)
			lower_cost_number = current->num;
		prev_cost = total_cost;
		printf("total_cost: %zu\n", total_cost);
		puts("");
		current = current->next;
		base_cost++;
	}
	printf("lower_cost_number: %d\n", lower_cost_number);
}

void	sort_insertion(t_cont *cont)
{
	size_t	steps1;
	size_t	steps2;
	bool	is_reverse;

	push_b(cont->stack_a, cont->stack_b, cont->ops);
	push_b(cont->stack_a, cont->stack_b, cont->ops);
	print_stack(cont);


	is_reverse = false;
	if (get_max(cont->stack_b) < dstack_peek(cont->stack_a))
	{
		puts("max");
		steps1 = get_steps_to_key_from_top2(cont->stack_b, get_max(cont->stack_b));
		steps2 = get_steps_to_key_from_bottom2(cont->stack_b, get_max(cont->stack_b));
	}
	else if (dstack_peek(cont->stack_a) < get_min(cont->stack_b))
	{
		puts("min");
		steps1 = get_steps_to_key_from_top2(cont->stack_b, get_max(cont->stack_b));
		steps2 = get_steps_to_key_from_bottom2(cont->stack_b, get_max(cont->stack_b));
	}
	else
	{
		puts("normal");
		steps1 = get_insert_index_from_top(cont->stack_b, dstack_peek(cont->stack_a));
		steps2 = get_insert_index_from_bottom(cont->stack_b, dstack_peek(cont->stack_a));
	}
	if (steps1 < steps2)
		is_reverse = false;
	else
		is_reverse = true;
	printf("steps(top): %zu, steps(bottom): %zu, reverse?: %d\n", steps1, steps2, is_reverse);
	puts("");
	/* rotate_push(cont, steps1, steps2); */

	calcurate_cost(cont);
}
