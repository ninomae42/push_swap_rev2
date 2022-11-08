#include "push_swap.h"

size_t	get_insert_cost_to_b(t_cont *cont, bool *is_reverse)
{
	size_t	cost_top;
	size_t	cost_bottom;

	*is_reverse = false;
	if (get_max(cont->stack_b) < dstack_peek(cont->stack_a))
	{
		puts("max");
		cost_top = get_costs_from_top(cont->stack_b, get_max(cont->stack_b));
		cost_bottom = get_costs_from_bottom(cont->stack_b, get_max(cont->stack_b));
	}
	else if (dstack_peek(cont->stack_a) < get_min(cont->stack_b))
	{
		puts("min");
		cost_top = get_costs_from_top(cont->stack_b, get_max(cont->stack_b));
		cost_bottom = get_costs_from_bottom(cont->stack_b, get_max(cont->stack_b));
	}
	else
	{
		puts("normal");
		cost_top = get_insert_costs_from_top(cont->stack_b, dstack_peek(cont->stack_a));
		cost_bottom = get_insert_costs_from_bottom(cont->stack_b, dstack_peek(cont->stack_a));
	}
	if (cost_top < cost_bottom)
		*is_reverse = false;
	else
		*is_reverse = true;
	if (*is_reverse)
		return (cost_bottom);
	else
		return (cost_top);
}

size_t	get_total_insertion_cost(t_cont *cont, int key)
{
	size_t	cost_a;
	size_t	cost_b;
	bool	is_reverse;
	size_t	total_cost;

	cost_b = get_insert_cost_to_b(cont, &is_reverse);
	cost_a = get_costs_from_top(cont->stack_a, key);
	total_cost = 0;
	if (is_reverse)
		total_cost = cost_a + cost_b;
	else
	{
		if (cost_a < cost_b)
			total_cost = cost_a + (cost_b - cost_a);
		else
			total_cost = cost_a + (cost_a - cost_b);
	}
	return (total_cost);
}

void	sort_insertion(t_cont *cont)
{
	size_t	cost_top;
	size_t	cost_bottom;
	bool	is_reverse;

	push_b(cont->stack_a, cont->stack_b, cont->ops);
	push_b(cont->stack_a, cont->stack_b, cont->ops);
	print_stack(cont);


	is_reverse = false;
	if (get_max(cont->stack_b) < dstack_peek(cont->stack_a))
	{
		puts("max");
		cost_top = get_costs_from_top(cont->stack_b, get_max(cont->stack_b));
		cost_bottom = get_costs_from_bottom(cont->stack_b, get_max(cont->stack_b));
	}
	else if (dstack_peek(cont->stack_a) < get_min(cont->stack_b))
	{
		puts("min");
		cost_top = get_costs_from_top(cont->stack_b, get_max(cont->stack_b));
		cost_bottom = get_costs_from_bottom(cont->stack_b, get_max(cont->stack_b));
	}
	else
	{
		puts("normal");
		cost_top = get_insert_costs_from_top(cont->stack_b, dstack_peek(cont->stack_a));
		cost_bottom = get_insert_costs_from_bottom(cont->stack_b, dstack_peek(cont->stack_a));
	}
	if (cost_top < cost_bottom)
		is_reverse = false;
	else
		is_reverse = true;
	printf("steps(top): %zu, steps(bottom): %zu, reverse?: %d\n", cost_top, cost_bottom, is_reverse);
	puts("");
	/* rotate_push(cont, steps1, steps2); */

	calcurate_cost(cont);
}
