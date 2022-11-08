#include "push_swap.h"

bool	is_key_in_range_exist(t_dstack *stack, int k_min, int k_max)
{
	t_dnode	*nil;
	t_dnode	*current;

	nil = stack->nil;
	current = nil->next;
	while (current != NULL && current != nil)
	{
		if (k_min < current->num && current->num <= k_max)
			return (true);
		current = current->next;
	}
	return (false);
}

void	insertion_sort(t_cont *cont, size_t low, size_t high, size_t total_size)
{
	size_t	mid1;
	size_t	mid2;

	// こっから3分割したものをマージしていく
	puts("--- Insertion Sort Start ---");
	/* low = high - total_size + 1; */
	mid1 = low + ((high - low) / 3);
	mid2 = low + 2 * ((high - low) / 3) + 1;
	printf("low: %zu, mid1: %zu, mid2: %zu, high: %zu, total_size: %zu\n", low, mid1, mid2, high, total_size);
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
	puts("stackA");
	dstack_print(cont->stack_a);
	puts("stackB");
	dstack_print(cont->stack_b);
	puts("--- Insertion Sort Done ---\n");
	return ;
}

void	prepare(t_cont *cont, size_t low, size_t high, size_t total_size)
{
	size_t	mid1;
	size_t	mid2;

	if (high - low < 10)
		return ;
	mid1 = low + ((high - low) / 3);
	mid2 = low + 2 * ((high - low) / 3) + 1;

	// 次の準備
	puts("--- Preparation for Next Start ---");
	printf("low: %zu, mid1: %zu, mid2: %zu, high: %zu, total_size: %zu\n", low, mid1, mid2, high, total_size);
	size_t	rotate_cnt = 0;
	/* while (is_key_in_range_exist(cont->stack_b, mid1, high)) */
	while (is_gte_key_and_lte_key_exist(cont->stack_b, mid1, high))
	{
		if ((int)low <= dstack_peek(cont->stack_b))
		{
			if ((int)mid2 < dstack_peek(cont->stack_b))
			{
				puts("pa ra");
				push_a(cont->stack_a, cont->stack_b, cont->ops);
				rotate_a(cont->stack_a, cont->ops);
				rotate_cnt++;
			}
			else if ((int)mid1 < dstack_peek(cont->stack_b))
			{
				puts("pa");
				push_a(cont->stack_a, cont->stack_b, cont->ops);
			}
			else
			{
				puts("rb");
				rotate_b(cont->stack_b, cont->ops);
			}
		}
		else
		{
			int	max = get_dstack_max(cont->stack_b);
			size_t	steps = get_steps_to_key_from_bottom(cont->stack_b, max);
			while (steps != 0)
			{
				puts("rrb");
				reverse_rotate_b(cont->stack_b, cont->ops);
				steps--;
			}
			if ((int)mid2 < dstack_peek(cont->stack_b))
			{
				puts("pa ra");
				push_a(cont->stack_a, cont->stack_b, cont->ops);
				rotate_a(cont->stack_a, cont->ops);
				rotate_cnt++;
			}
			else if ((int)mid1 < dstack_peek(cont->stack_b))
			{
				puts("pa");
				push_a(cont->stack_a, cont->stack_b, cont->ops);
			}
		}
		puts("stackA");
		dstack_print(cont->stack_a);
		puts("stackB");
		dstack_print(cont->stack_b);
		puts("");
	}
	/* while (is_key_in_range_exist(cont->stack_a, mid1, mid2)) */
	while (is_gte_key_and_lte_key_exist(cont->stack_a, mid1, mid2))
	{
		puts("pb");
		push_b(cont->stack_a, cont->stack_b, cont->ops);
	}
	while (rotate_cnt != 0)
	{
		puts("rra");
		puts("pb");
		reverse_rotate_a(cont->stack_a, cont->ops);
		push_b(cont->stack_a, cont->stack_b, cont->ops);
		rotate_cnt--;
	}
	puts("stackA");
	dstack_print(cont->stack_a);
	puts("stackB");
	dstack_print(cont->stack_b);
	puts("");
	puts("--- Preparation for Next End ---");
}

void	merge(t_cont *cont, size_t low, size_t high, size_t total_size)
{
	size_t	mid1;
	size_t	mid2;

	if (high - low < 2)
		return ;
	mid1 = low + ((high - low) / 3);
	mid2 = low + 2 * ((high - low) / 3) + 1;

	// 次の準備
	if (high != total_size * 3 - 1)
	{
		high = high - total_size;
		low = high - total_size + 1;
		mid1 = low + ((high - low) / 3);
		mid2 = low + 2 * ((high - low) / 3) + 1;
		printf("low: %zu, mid1: %zu, mid2: %zu, high: %zu, total_size: %zu\n", low, mid1, mid2, high, total_size);
		size_t	rotate_cnt = 0;
		while (is_key_in_range_exist(cont->stack_b, mid1, high))
		{
			if ((int)low <= dstack_peek(cont->stack_b))
			{
				if ((int)mid2 < dstack_peek(cont->stack_b))
				{
					puts("pa ra");
					push_a(cont->stack_a, cont->stack_b, cont->ops);
					rotate_a(cont->stack_a, cont->ops);
					rotate_cnt++;
				}
				else if ((int)mid1 < dstack_peek(cont->stack_b))
				{
					puts("pa");
					push_a(cont->stack_a, cont->stack_b, cont->ops);
				}
				else
				{
					puts("rb");
					rotate_b(cont->stack_b, cont->ops);
				}
			}
			else
			{
				int	max = get_dstack_max(cont->stack_b);
				size_t	steps = get_steps_to_key_from_bottom(cont->stack_b, max);
				while (steps != 0)
				{
					puts("rrb");
					reverse_rotate_b(cont->stack_b, cont->ops);
					steps--;
				}
				if ((int)mid2 < dstack_peek(cont->stack_b))
				{
					puts("pa ra");
					push_a(cont->stack_a, cont->stack_b, cont->ops);
					rotate_a(cont->stack_a, cont->ops);
					rotate_cnt++;
				}
				else if ((int)mid1 < dstack_peek(cont->stack_b))
				{
					puts("pa");
					push_a(cont->stack_a, cont->stack_b, cont->ops);
				}
			}
		}
		while (is_key_in_range_exist(cont->stack_a, mid1, mid2))
		{
			puts("pb");
			push_b(cont->stack_a, cont->stack_b, cont->ops);
		}
		while (rotate_cnt != 0)
		{
			puts("rra");
			puts("pb");
			reverse_rotate_a(cont->stack_a, cont->ops);
			push_b(cont->stack_a, cont->stack_b, cont->ops);
			rotate_cnt--;
		}
		puts("stackA");
		dstack_print(cont->stack_a);
		puts("stackB");
		dstack_print(cont->stack_b);
		puts("");
	}
	// こっから3分割したものをマージしていく
	puts("--- Insertion Sort Start ---");
	low = high - total_size + 1;
	mid1 = low + ((high - low) / 3);
	mid2 = low + 2 * ((high - low) / 3) + 1;
	printf("low: %zu, mid1: %zu, mid2: %zu, high: %zu, total_size: %zu\n", low, mid1, mid2, high, total_size);
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
	puts("stackA");
	dstack_print(cont->stack_a);
	puts("stackB");
	dstack_print(cont->stack_b);
	puts("--- Insertion Sort Done ---\n");
	merge(cont, mid2, high, total_size);
}

/* void	dstack_merge_sort(t_cont *cont, size_t low, size_t high) */
void	dstack_merge_sort(t_cont *cont, size_t low, size_t high, size_t total_size)
{
	size_t	mid1;
	size_t	mid2;

	if (high - low < 2)
		return ;
	mid1 = low + ((high - low) / 3);
	mid2 = low + 2 * ((high - low) / 3) + 1;

	// stackを3分割する
	while (is_lt_key_exist(cont->stack_a, mid2)){
		if (dstack_peek(cont->stack_a) <= (int)mid1)
		{
			push_b(cont->stack_a, cont->stack_b, cont->ops);
			rotate_b(cont->stack_b, cont->ops);
		} else if (dstack_peek(cont->stack_a) <= (int)mid2)
			push_b(cont->stack_a, cont->stack_b, cont->ops);
		else
			rotate_a(cont->stack_a, cont->ops);
	}
	puts("stackA");
	dstack_print(cont->stack_a);
	puts("stackB");
	dstack_print(cont->stack_b);
	puts("");
	dstack_merge_sort(cont, mid2, high, total_size);

	/* printf("low: %zu, mid1: %zu, mid2: %zu, high: %zu, total_size: %zu\n", low, mid1, mid2, high, total_size); */
	/* prepare(cont, mid2, high, total_size); */
	/* insertion_sort(cont, low, high, total_size); */

	/* insertion_sort(cont, mid2, high, total_size); */
	/* insertion_sort(cont, mid1, mid2, total_size); */
	/* insertion_sort(cont, low, mid1, total_size); */
	/* merge(cont, mid2, high, total_size); */

	// こっから3分割したものをマージしていく
	/* puts("--- Insertion Sort Start ---"); */
	/* printf("low: %zu, mid1: %zu, mid2: %zu, high: %zu, total_size: %zu\n", low, mid1, mid2, high, total_size); */
	/* low = high - total_size + 1; */
	/* mid1 = low + ((high - low) / 3); */
	/* mid2 = low + 2 * ((high - low) / 3) + 1; */
	/* printf("low: %zu, mid1: %zu, mid2: %zu, high: %zu, total_size: %zu\n", low, mid1, mid2, high, total_size); */
	/* while (is_gte_key_and_lte_key_exist(cont->stack_b, low, high)) */
	/* { */
	/* 	int	max = get_dstack_max(cont->stack_b); */
	/* 	size_t	steps_top = get_steps_to_key_from_top(cont->stack_b, max); */
	/* 	size_t	steps_bottom = get_steps_to_key_from_bottom(cont->stack_b, max); */
	/* 	if (steps_top < steps_bottom) */
	/* 	{ */
	/* 		while (steps_top != 0) */
	/* 		{ */
	/* 			rotate_b(cont->stack_b, cont->ops); */
	/* 			steps_top--; */
	/* 		} */
	/* 	} */
	/* 	else */
	/* 	{ */
	/* 		while (steps_bottom != 0) */
	/* 		{ */
	/* 			reverse_rotate_b(cont->stack_b, cont->ops); */
	/* 			steps_bottom--; */
	/* 		} */
	/* 	} */
	/* 	push_a(cont->stack_a, cont->stack_b, cont->ops); */
	/* } */
	/* puts("stackA"); */
	/* dstack_print(cont->stack_a); */
	/* puts("stackB"); */
	/* dstack_print(cont->stack_b); */
	/* puts("--- Insertion Sort Done ---\n"); */
	/* return ; */
	/*  */
	/* printf("low: %zu, mid1: %zu, mid2: %zu, high: %zu, total_size: %zu\n", low, mid1, mid2, high, total_size); */
	/* high = high - total_size; */
	/* low = high - total_size + 1; */
	/* mid1 = low + ((high - low) / 3); */
	/* mid2 = low + 2 * ((high - low) / 3) + 1; */
	/* printf("low: %zu, mid1: %zu, mid2: %zu, high: %zu, total_size: %zu\n", low, mid1, mid2, high, total_size); */
	/* size_t	rotate_cnt = 0; */
	/*  */
	/* // 次の下準備 */
	/* while (is_key_in_range_exist(cont->stack_b, mid1, high)) */
	/* { */
	/* 	if ((int)low <= dstack_peek(cont->stack_b)) */
	/* 	{ */
	/* 		if ((int)mid2 < dstack_peek(cont->stack_b)) */
	/* 		{ */
	/* 			puts("pa ra"); */
	/* 			push_a(cont->stack_a, cont->stack_b, cont->ops); */
	/* 			rotate_a(cont->stack_a, cont->ops); */
	/* 			rotate_cnt++; */
	/* 		} */
	/* 		else if ((int)mid1 < dstack_peek(cont->stack_b)) */
	/* 		{ */
	/* 			puts("pa"); */
	/* 			push_a(cont->stack_a, cont->stack_b, cont->ops); */
	/* 		} */
	/* 		else */
	/* 		{ */
	/* 			puts("rb"); */
	/* 			rotate_b(cont->stack_b, cont->ops); */
	/* 		} */
	/* 	} */
	/* 	else */
	/* 	{ */
	/* 		int	max = get_dstack_max(cont->stack_b); */
	/* 		size_t	steps = get_steps_to_key_from_bottom(cont->stack_b, max); */
	/* 		while (steps != 0) */
	/* 		{ */
	/* 			puts("rrb"); */
	/* 			reverse_rotate_b(cont->stack_b, cont->ops); */
	/* 			steps--; */
	/* 		} */
	/* 		if ((int)mid2 < dstack_peek(cont->stack_b)) */
	/* 		{ */
	/* 			puts("pa ra"); */
	/* 			push_a(cont->stack_a, cont->stack_b, cont->ops); */
	/* 			rotate_a(cont->stack_a, cont->ops); */
	/* 			rotate_cnt++; */
	/* 		} */
	/* 		else if ((int)mid1 < dstack_peek(cont->stack_b)) */
	/* 		{ */
	/* 			puts("pa"); */
	/* 			push_a(cont->stack_a, cont->stack_b, cont->ops); */
	/* 		} */
	/* 	} */
	/* } */
	/* while (is_key_in_range_exist(cont->stack_a, mid1, mid2)) */
	/* { */
	/* 	puts("pb"); */
	/* 	push_b(cont->stack_a, cont->stack_b, cont->ops); */
	/* } */
	/* while (rotate_cnt != 0) */
	/* { */
	/* 	puts("rra"); */
	/* 	puts("pb"); */
	/* 	reverse_rotate_a(cont->stack_a, cont->ops); */
	/* 	push_b(cont->stack_a, cont->stack_b, cont->ops); */
	/* 	rotate_cnt--; */
	/* } */
	/* puts("stackA"); */
	/* dstack_print(cont->stack_a); */
	/* puts("stackB"); */
	/* dstack_print(cont->stack_b); */
	/* puts(""); */

	/* dstack_merge_sort(cont, mid1, mid2); */
	/* dstack_merge_sort(cont, low, mid1); */
	/*  */
	/* merge(cont, low, mid1, mid2, high); */
}

//void	dstack_merge_sort(t_cont *cont, size_t low, size_t high, size_t total_size)
//{
//	size_t	mid1;
//	size_t	mid2;
//
//	/* printf("low: %zu, high: %zu, total_size: %zu\n", low, high, total_size); */
//	// If stack size is 1 then do nothing
//	if (high - low < 2)
//		return ;
//	mid1 = low + ((high - low) / 3);
//	mid2 = low + 2 * ((high - low) / 3) + 1;
//	/* printf("mid1: %zu, mid2: %zu\n", mid1, mid2); */
//	/* puts("before"); */
//	/* dstack_print(cont->stack_a); */
//	/* puts("\n"); */
//
//	/* printf("low: %zu, mid1: %zu, mid2: %zu, high: %zu\n", low, mid1, mid2, high); */
//
//	// stackを3分割する
//	/* while (is_lte_key_exist(cont->stack_a, mid2)){ */
//	while (is_lt_key_exist(cont->stack_a, mid2)){
//		if (dstack_peek(cont->stack_a) <= (int)mid1)
//		{
//			push_b(cont->stack_a, cont->stack_b, cont->ops);
//			rotate_b(cont->stack_b, cont->ops);
//		} else if (dstack_peek(cont->stack_a) <= (int)mid2)
//			push_b(cont->stack_a, cont->stack_b, cont->ops);
//		else
//			rotate_a(cont->stack_a, cont->ops);
//	}
//	/* puts("stackA"); */
//	/* dstack_print(cont->stack_a); */
//	/* puts("stackB"); */
//	/* dstack_print(cont->stack_b); */
//	/* puts(""); */
//	dstack_merge_sort(cont, mid2, high, total_size);
//
//	// こっから3分割したものをマージしていく
//	while (is_gte_key_and_lte_key_exist(cont->stack_b, low, high))
//	{
//		int	max = get_dstack_max(cont->stack_b);
//		size_t	steps_top = get_steps_to_key_from_top(cont->stack_b, max);
//		size_t	steps_bottom = get_steps_to_key_from_bottom(cont->stack_b, max);
//		if (steps_top < steps_bottom)
//		{
//			while (steps_top != 0)
//			{
//				rotate_b(cont->stack_b, cont->ops);
//				steps_top--;
//			}
//		}
//		else
//		{
//			while (steps_bottom != 0)
//			{
//				reverse_rotate_b(cont->stack_b, cont->ops);
//				steps_bottom--;
//			}
//		}
//		push_a(cont->stack_a, cont->stack_b, cont->ops);
//	}
//	puts("stackA");
//	dstack_print(cont->stack_a);
//	puts("stackB");
//	dstack_print(cont->stack_b);
//	puts("");
//	return ;
//
//	printf("low: %zu, mid1: %zu, mid2: %zu, high: %zu, total_size: %zu\n", low, mid1, mid2, high, total_size);
//	high = high - total_size;
//	low = high - total_size + 1;
//	mid1 = low + ((high - low) / 3);
//	mid2 = low + 2 * ((high - low) / 3) + 1;
//	printf("low: %zu, mid1: %zu, mid2: %zu, high: %zu, total_size: %zu\n", low, mid1, mid2, high, total_size);
//	size_t	rotate_cnt = 0;
//
//	// 次の下準備
//	while (is_key_in_range_exist(cont->stack_b, mid1, high))
//	{
//		if ((int)low <= dstack_peek(cont->stack_b))
//		{
//			if ((int)mid2 < dstack_peek(cont->stack_b))
//			{
//				puts("pa ra");
//				push_a(cont->stack_a, cont->stack_b, cont->ops);
//				rotate_a(cont->stack_a, cont->ops);
//				rotate_cnt++;
//			}
//			else if ((int)mid1 < dstack_peek(cont->stack_b))
//			{
//				puts("pa");
//				push_a(cont->stack_a, cont->stack_b, cont->ops);
//			}
//			else
//			{
//				puts("rb");
//				rotate_b(cont->stack_b, cont->ops);
//			}
//		}
//		else
//		{
//			int	max = get_dstack_max(cont->stack_b);
//			size_t	steps = get_steps_to_key_from_bottom(cont->stack_b, max);
//			while (steps != 0)
//			{
//				puts("rrb");
//				reverse_rotate_b(cont->stack_b, cont->ops);
//				steps--;
//			}
//			if ((int)mid2 < dstack_peek(cont->stack_b))
//			{
//				puts("pa ra");
//				push_a(cont->stack_a, cont->stack_b, cont->ops);
//				rotate_a(cont->stack_a, cont->ops);
//				rotate_cnt++;
//			}
//			else if ((int)mid1 < dstack_peek(cont->stack_b))
//			{
//				puts("pa");
//				push_a(cont->stack_a, cont->stack_b, cont->ops);
//			}
//		}
//	}
//	while (rotate_cnt != 0)
//	{
//		reverse_rotate_a(cont->stack_a, cont->ops);
//		rotate_cnt--;
//	}
//	puts("stackA");
//	dstack_print(cont->stack_a);
//	puts("stackB");
//	dstack_print(cont->stack_b);
//	puts("");
//
//	/* dstack_merge_sort(cont, mid1, mid2); */
//	/* dstack_merge_sort(cont, low, mid1); */
//	/*  */
//	/* merge(cont, low, mid1, mid2, high); */
//}
