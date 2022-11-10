/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:59:15 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/10 20:59:16 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// calculate placement cost on stack_a with stack_b's top value
void	calculate_cost_stack_a(t_dstack *stack, size_t a_top, t_cm *cm)
{
	size_t	cost_top;
	size_t	cost_bottom;

	cost_top = 0;
	cost_bottom = 0;
	cost_top = get_cost_from_top(stack, a_top);
	cost_bottom = get_cost_from_bottom(stack, a_top);
	if (cost_top == cost_bottom)
	{
		cm->is_reverse_a = cm->is_reverse_b;
		cm->cost_a = cost_top;
	}
	else if (cost_top < cost_bottom)
	{
		cm->is_reverse_a = false;
		cm->cost_a = cost_top;
	}
	else
	{
		cm->is_reverse_a = true;
		cm->cost_a = cost_bottom;
	}
}
