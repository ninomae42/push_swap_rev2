/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost_stack_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:57:09 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/10 20:57:11 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_placement_cost_from_top(t_dstack *stack, size_t value);
static size_t	get_placement_cost_from_bottom(t_dstack *stack, size_t value);
static size_t	get_placement_cost_when_size2(t_dstack *stack, size_t value);

// calculate placement cost on stack_b with stack_a's top value
void	calculate_cost_stack_b(
		t_dstack *stack, size_t a_top, t_cm *cost_manager)
{
	size_t	cost_top;
	size_t	cost_bottom;

	cost_top = 0;
	cost_bottom = 0;
	if (get_max(stack) < a_top || a_top < get_min(stack))
	{
		cost_top = get_cost_from_top(stack, get_max(stack));
		cost_bottom = get_cost_from_bottom(stack, get_max(stack));
	}
	else
	{
		cost_top = get_placement_cost_from_top(stack, a_top);
		cost_bottom = get_placement_cost_from_bottom(stack, a_top);
	}
	if (cost_top <= cost_bottom)
	{
		cost_manager->is_reverse_b = false;
		cost_manager->cost_b = cost_top;
	}
	else
	{
		cost_manager->is_reverse_b = true;
		cost_manager->cost_b = cost_bottom;
	}
}

// get a moving cost from top with given value must be placed properly
static size_t	get_placement_cost_from_top(t_dstack *stack, size_t value)
{
	size_t	cost;
	t_dnode	*nil;
	t_dnode	*current;

	nil = stack->nil;
	current = nil->next;
	if (stack->size == 2)
		return (get_placement_cost_when_size2(stack, value));
	cost = 1;
	while (current != NULL && current->next != nil)
	{
		if (current->next->num < value && value < current->num)
			break ;
		cost++;
		current = current->next;
	}
	return (cost);
}

// get a moving cost from top with given value must be placed properly
static size_t	get_placement_cost_from_bottom(t_dstack *stack, size_t value)
{
	size_t	cost;
	t_dnode	*nil;
	t_dnode	*current;

	nil = stack->nil;
	current = nil->prev;
	if (stack->size == 2)
		return (get_placement_cost_when_size2(stack, value));
	cost = 1;
	while (current != NULL && current->prev != nil)
	{
		if (current->num < value && value < current->prev->num)
			break ;
		cost++;
		current = current->prev;
	}
	return (cost);
}

static size_t	get_placement_cost_when_size2(t_dstack *stack, size_t value)
{
	t_dnode	*first;
	t_dnode	*last;

	first = stack->nil->next;
	last = stack->nil->prev;
	if (value < first->num && last->num < value)
		return (1);
	else
		return (0);
}
