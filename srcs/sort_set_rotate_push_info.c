/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_set_rotate_push_info.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:55:33 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/10 20:57:34 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_rotate_and_push_info_same_direaction(t_cm *cm);

void	set_rotate_and_push_info(t_cost_manager *cm)
{
	if (cm->is_reverse_a == cm->is_reverse_b)
		set_rotate_and_push_info_same_direaction(cm);
	else
	{
		cm->rotate_cnt_a = cm->cost_a;
		cm->rotate_cnt_b = cm->cost_b;
		cm->rotate_cnt_both = 0;
	}
	cm->rotate_is_reverse_a = cm->is_reverse_a;
	cm->rotate_is_reverse_b = cm->is_reverse_b;
}

static void	set_rotate_and_push_info_same_direaction(t_cm *cm)
{
	if (cm->cost_a == 0 || cm->cost_b == 0)
	{
		cm->rotate_cnt_a = cm->cost_a;
		cm->rotate_cnt_b = cm->cost_b;
		cm->rotate_cnt_both = 0;
	}
	else if (cm->cost_a == cm->cost_b)
	{
		cm->rotate_cnt_both = cm->cost_a;
		cm->rotate_cnt_a = 0;
		cm->rotate_cnt_b = 0;
	}
	else if (cm->cost_a < cm->cost_b)
	{
		cm->rotate_cnt_both = cm->cost_a;
		cm->rotate_cnt_b = cm->cost_b - cm->cost_a;
		cm->rotate_cnt_a = 0;
	}
	else
	{
		cm->rotate_cnt_both = cm->cost_b;
		cm->rotate_cnt_a = cm->cost_a - cm->cost_b;
		cm->rotate_cnt_b = 0;
	}
}
