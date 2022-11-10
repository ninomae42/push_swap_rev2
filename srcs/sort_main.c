/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:55:58 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/10 20:56:01 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_main(t_controller *cont)
{
	if (cont->stack_a->size == 3)
	{
		sort_lte_three(cont);
		return ;
	}
	push_b(cont->stack_a, cont->stack_b, cont->ops);
	push_b(cont->stack_a, cont->stack_b, cont->ops);
	while (3 < cont->stack_a->size)
	{
		traverse_and_calculate_cost(cont);
		rotate_push_with_cost_manager_info(cont, cont->cm);
	}
	sort_lte_three(cont);
	while (cont->stack_b->size)
		push_back_from_b_to_a(cont);
	seichi(cont);
}
