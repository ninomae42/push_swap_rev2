/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lte5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:46:45 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/06 16:46:46 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two_base(t_dstack *stack, t_ops *ops)
{
	if (is_stack_sorted(stack))
		return ;
	swap_a(stack, ops);
}

static void	sort_three_base(t_dstack *stack, t_ops *ops)
{
	int	first;
	int	second;
	int	third;

	if (stack == NULL || ops == NULL || is_stack_sorted(stack))
		return ;
	first = stack->nil->next->num;
	second = stack->nil->next->next->num;
	third = stack->nil->next->next->next->num;
	if (first < third)
	{
		swap_a(stack, ops);
		if (first < second)
			rotate_a(stack, ops);
	}
	else if (first > third && first > second)
	{
		rotate_a(stack, ops);
		if (second > third)
			swap_a(stack, ops);
	}
	else
		reverse_rotate_a(stack, ops);
}

static void	sort_lte_three(t_cont *controller)
{
	if (is_stack_sorted(controller->stack_a))
		return ;
	if (controller->stack_a->size == 2)
		sort_two_base(controller->stack_a, controller->ops);
	else
		sort_three_base(controller->stack_a, controller->ops);
}

static void	sort_five_base(
		t_dstack *stack_a, t_dstack *stack_b, t_ops *ops, int key)
{
	while (is_lte_key_exist(stack_a, key))
	{
		if (dstack_peek(stack_a) <= key)
			push_b(stack_a, stack_b, ops);
		else
			rotate_a(stack_a, ops);
	}
	if (is_stack_sorted(stack_b))
		swap_b(stack_b, ops);
	sort_three_base(stack_a, ops);
	while (0 < stack_b->size)
		push_a(stack_a, stack_b, ops);
}

void	sort_lte_five(t_cont *controller)
{
	if (is_stack_sorted(controller->stack_a))
		return ;
	if (controller->stack_a->size < 4)
	{
		sort_lte_three(controller);
		return ;
	}
	sort_five_base(
		controller->stack_a, controller->stack_b, controller->ops, 1);
}
