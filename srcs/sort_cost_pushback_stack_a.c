/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost_pushback_stack_a.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:57:43 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/10 20:57:44 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_placement_cost_from_top(t_dstack *stack, size_t value);
static size_t	get_placement_cost_from_bottom(t_dstack *stack, size_t value);
static void		calculate_cost_cases(t_dstack *stack, size_t b_top,
					size_t *cost_top, size_t *cost_bottom);

// calculate placement cost on stack_a with stack_b's top value
size_t	calculate_cost_pushback_stack_a(
		t_dstack *stack, size_t b_top, bool *is_reverse)
{
	size_t	cost_top;
	size_t	cost_bottom;

	cost_top = 0;
	cost_bottom = 0;
	calculate_cost_cases(stack, b_top, &cost_top, &cost_bottom);
	if (cost_top < cost_bottom)
	{
		*is_reverse = false;
		return (cost_top);
	}
	else
	{
		*is_reverse = true;
		return (cost_bottom);
	}
}

static void	calculate_cost_cases(t_dstack *stack, size_t b_top,
			size_t *cost_top, size_t *cost_bottom)
{
	if (get_max(stack) < b_top || b_top < get_min(stack))
	{
		*cost_top = get_cost_from_top(stack, get_min(stack));
		*cost_bottom = get_cost_from_bottom(stack, get_min(stack));
	}
	else if (dstack_find(stack, b_top + 1))
	{
		*cost_top = get_cost_from_top(stack, b_top + 1);
		*cost_bottom = get_cost_from_bottom(stack, b_top + 1);
	}
	else if (dstack_find(stack, b_top - 1))
	{
		*cost_top = get_cost_from_top(stack, b_top - 1) + 1;
		*cost_bottom = get_cost_from_bottom(stack, b_top - 1);
		if (*cost_bottom != 0)
			(*cost_bottom)--;
	}
	else
	{
		*cost_top = get_placement_cost_from_top(stack, b_top);
		*cost_bottom = get_placement_cost_from_bottom(stack, b_top);
	}
}

// get a moving cost from top with given value must be placed properly
static size_t	get_placement_cost_from_top(t_dstack *stack, size_t value)
{
	size_t	cost;
	t_dnode	*nil;
	t_dnode	*current;

	nil = stack->nil;
	current = nil->next->next;
	cost = 1;
	while (current != NULL && current != nil)
	{
		if (current->prev->num < value && value < current->num)
			break ;
		cost++;
		current = current->next;
	}
	return (cost);
}

// get a moving cost from bottom with given value must be placed properly
static size_t	get_placement_cost_from_bottom(t_dstack *stack, size_t value)
{
	size_t	cost;
	t_dnode	*nil;
	t_dnode	*current;

	nil = stack->nil;
	current = nil->prev->prev;
	cost = 1;
	while (current != NULL && current->prev != nil)
	{
		if (current->num < value && value < current->next->num)
			break ;
		cost++;
		current = current->prev;
	}
	return (cost);
}
