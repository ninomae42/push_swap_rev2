/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pushback_stack_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:58:42 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/10 20:58:43 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_from_b_to_a(t_controller *cont)
{
	size_t	top_b;
	size_t	cost;
	bool	is_reverse;

	top_b = dstack_peek(cont->stack_b);
	is_reverse = false;
	cost = calculate_cost_pushback_stack_a(cont->stack_a, top_b, &is_reverse);
	if (is_reverse)
		while (cost != 0 && cost--)
			reverse_rotate_a(cont->stack_a, cont->ops);
	else
		while (cost != 0 && cost--)
			rotate_a(cont->stack_a, cont->ops);
	push_a(cont->stack_a, cont->stack_b, cont->ops);
}

void	seichi(t_controller *cont)
{
	size_t	min_a;
	size_t	cost_top;
	size_t	cost_bottom;

	min_a = get_min(cont->stack_a);
	cost_top = get_cost_from_top(cont->stack_a, min_a);
	cost_bottom = get_cost_from_bottom(cont->stack_a, min_a);
	if (cost_top < cost_bottom)
		while (cost_top != 0 && cost_top--)
			rotate_a(cont->stack_a, cont->ops);
	else
		while (cost_bottom != 0 && cost_bottom--)
			reverse_rotate_a(cont->stack_a, cont->ops);
}
