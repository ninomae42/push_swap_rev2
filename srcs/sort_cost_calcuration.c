/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost_calcuration.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:55:48 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/10 20:55:50 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calculate_total_cost(t_cm *cm);

// traverse all element on stack 'A'. And find minimum cost number on stack_a
void	traverse_and_calculate_cost(t_cont *cont)
{
	t_dnode		*nil;
	t_dnode		*current;
	t_cm		*cm;

	nil = cont->stack_a->nil;
	current = nil->next;
	cm = cont->cm;
	cm->min_cost = SIZE_T_MAX;
	cm->min_cost_number = 0;
	while (current != NULL && current != nil)
	{
		calculate_cost_stack_b(cont->stack_b, current->num, cm);
		calculate_cost_stack_a(cont->stack_a, current->num, cm);
		calculate_total_cost(cm);
		if (cm->total_cost < cm->min_cost)
		{
			cm->min_cost = cm->total_cost;
			cm->min_cost_number = current->num;
			set_rotate_and_push_info(cm);
		}
		current = current->next;
	}
}

// calculate total cost based on cost of both stack
// (rotate_same discound enabled)
static void	calculate_total_cost(t_cm *cm)
{
	if (cm->is_reverse_a == cm->is_reverse_b)
	{
		if (cm->cost_a < cm->cost_b)
			cm->total_cost = cm->cost_a + (cm->cost_b - cm->cost_a);
		else
			cm->total_cost = cm->cost_b + (cm->cost_a - cm->cost_b);
	}
	else
		cm->total_cost = cm->cost_a + cm->cost_b;
	cm->total_cost += 1;
}
