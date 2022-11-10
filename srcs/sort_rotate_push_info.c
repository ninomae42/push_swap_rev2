/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate_push_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:59:01 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/10 20:59:02 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_push_when_same_direction(t_cont *cont, t_cost_manager *cm);
static void	rotate_push_when_opposite_direction(
				t_cont *cont, t_cost_manager *cm);

void	rotate_push_with_cost_manager_info(t_cont *cont, t_cost_manager *cm)
{
	if (cm->rotate_is_reverse_a == cm->rotate_is_reverse_b)
		rotate_push_when_same_direction(cont, cm);
	else
		rotate_push_when_opposite_direction(cont, cm);
	push_b(cont->stack_a, cont->stack_b, cont->ops);
}

static void	rotate_push_when_same_direction(t_cont *cont, t_cost_manager *cm)
{
	if (cm->rotate_is_reverse_a)
	{
		while (cm->rotate_cnt_both != 0 && cm->rotate_cnt_both--)
			reverse_rotate_same(cont->stack_a, cont->stack_b, cont->ops);
		while (cm->rotate_cnt_a != 0 && cm->rotate_cnt_a--)
			reverse_rotate_a(cont->stack_a, cont->ops);
		while (cm->rotate_cnt_b != 0 && cm->rotate_cnt_b--)
			reverse_rotate_b(cont->stack_b, cont->ops);
	}
	else
	{
		while (cm->rotate_cnt_both != 0 && cm->rotate_cnt_both--)
			rotate_same(cont->stack_a, cont->stack_b, cont->ops);
		while (cm->rotate_cnt_a != 0 && cm->rotate_cnt_a--)
			rotate_a(cont->stack_a, cont->ops);
		while (cm->rotate_cnt_b != 0 && cm->rotate_cnt_b--)
			rotate_b(cont->stack_b, cont->ops);
	}
}

static void	rotate_push_when_opposite_direction(
		t_cont *cont, t_cost_manager *cm)
{
	if (cm->rotate_is_reverse_a)
		while (cm->rotate_cnt_a != 0 && cm->rotate_cnt_a--)
			reverse_rotate_a(cont->stack_a, cont->ops);
	else
		while (cm->rotate_cnt_a != 0 && cm->rotate_cnt_a--)
			rotate_a(cont->stack_a, cont->ops);
	if (cm->rotate_is_reverse_b)
		while (cm->rotate_cnt_b != 0 && cm->rotate_cnt_b--)
			reverse_rotate_b(cont->stack_b, cont->ops);
	else
		while (cm->rotate_cnt_b != 0 && cm->rotate_cnt_b--)
			rotate_b(cont->stack_b, cont->ops);
}
