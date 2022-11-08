#include "push_swap.h"

void	split_stack_first(t_cont *cont, size_t low, size_t high)
{
	size_t	mid1;
	size_t	mid2;

	if (high - low < 1)
		return ;
	mid1 = low + ((high - low) / 3);
	mid2 = low + 2 * ((high - low) / 3) + 1;
	/* printf("low: %zu, mid1: %zu, mid2: %zu, high: %zu\n", low, mid1, mid2, high); */
	while (is_lte_key_exist(cont->stack_a, mid2))
	{
		if (dstack_peek(cont->stack_a) <= (int)mid1)
		{
			push_b(cont->stack_a, cont->stack_b, cont->ops);
			rotate_b(cont->stack_b, cont->ops);
		}
		else if (dstack_peek(cont->stack_a) <= (int)mid2)
			push_b(cont->stack_a, cont->stack_b, cont->ops);
		else
			rotate_a(cont->stack_a, cont->ops);
	}
	split_stack_first(cont, mid2, high);
}

void	insertion_sort_first(t_cont *cont, size_t low, size_t high)
{
	/* size_t	mid1; */
	/* size_t	mid2; */

	// こっから3分割したものをマージしていく
	/* puts("--- Insertion Sort Start ---"); */
	/* low = high - total_size + 1; */
	/* mid1 = low + ((high - low) / 3); */
	/* mid2 = low + 2 * ((high - low) / 3) + 1; */
	/* printf("low: %zu, mid1: %zu, mid2: %zu, high: %zu\n", low, mid1, mid2, high); */
	while (is_gte_key_and_lte_key_exist(cont->stack_b, low, high))
	{
		int	max = get_dstack_max(cont->stack_b);
		size_t	steps_top = get_steps_to_key_from_top(cont->stack_b, max);
		size_t	steps_bottom = get_steps_to_key_from_bottom(cont->stack_b, max);
		if (steps_top < steps_bottom)
		{
			while (steps_top != 0)
			{
				rotate_b(cont->stack_b, cont->ops);
				steps_top--;
			}
		}
		else
		{
			while (steps_bottom != 0)
			{
				reverse_rotate_b(cont->stack_b, cont->ops);
				steps_bottom--;
			}
		}
		push_a(cont->stack_a, cont->stack_b, cont->ops);
	}
	/* puts("stackA"); */
	/* dstack_print(cont->stack_a); */
	/* puts("stackB"); */
	/* dstack_print(cont->stack_b); */
	/* puts("--- Insertion Sort Done ---\n"); */
	return ;
}

void	split_stack_second(t_cont *cont, size_t low, size_t high)
{
	/* size_t	mid1; */
	size_t	mid2;
	size_t	steps;
	size_t	rotate_cnt;

	if (cont->stack_b->size == 0)
		return ;
	/* mid1 = low + ((high - low) / 3); */
	mid2 = low + 2 * ((high - low) / 3) + 1;
	/* printf("low: %zu, mid1: %zu, mid2: %zu, high: %zu\n", low, mid1, mid2, high); */
	rotate_cnt = 0;
	while (is_gte_key_and_lte_key_exist(cont->stack_b, low, high))
	{
		if (dstack_peek(cont->stack_b) < (int)low)
		{
			if (cont->stack_b->nil->next->next->num < (int)low)
			{
				steps = get_steps_to_key_from_bottom(cont->stack_b, get_dstack_max(cont->stack_b));
				while (steps--)
					reverse_rotate_b(cont->stack_b, cont->ops);
			}
			else
				rotate_b(cont->stack_b, cont->ops);
		}
		else if (dstack_peek(cont->stack_b) <= (int)mid2)
			push_a(cont->stack_a, cont->stack_b, cont->ops);
		else
		{
			push_a(cont->stack_a, cont->stack_b, cont->ops);
			rotate_a(cont->stack_a, cont->ops);
			rotate_cnt++;
		}
	}
	split_stack_first(cont, low, mid2);
	while (rotate_cnt--)
	{
		reverse_rotate_a(cont->stack_a, cont->ops);
		push_b(cont->stack_a, cont->stack_b, cont->ops);
	}
}

void	sort_lte_100(t_cont *cont, size_t low, size_t high)
{
	size_t	mid1;
	size_t	mid2;
	
	mid1 = low + ((high - low) / 3);
	mid2 = low + 2 * ((high - low) / 3) + 1;
	
	split_stack_first(cont, low, high);
	/* puts("\nstackA"); */
	/* dstack_print(cont->stack_a); */
	/* puts("stackB"); */
	/* dstack_print(cont->stack_b); */
	/* puts(""); */
	/*  */
	(void)mid1;
	(void)mid2;
	insertion_sort_first(cont, low, high);

	/* insertion_sort_first(cont, mid2 + 1, high); */
	/* split_stack_second(cont, mid1 + 1, mid2); */
	/* insertion_sort_first(cont, mid1 + 1, mid2); */
	/* split_stack_second(cont, low, mid1); */
	/* insertion_sort_first(cont, low, mid1); */

	/* puts("\nstackA"); */
	/* dstack_print(cont->stack_a); */
	/* puts("stackB"); */
	/* dstack_print(cont->stack_b); */
	/* puts(""); */
	/* split_stack_first(cont, mid2, high); */
}
