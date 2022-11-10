/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:58:07 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/10 20:58:09 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// find the maximum value on given stack
size_t	get_max(t_dstack *stack)
{
	t_dnode	*nil;
	t_dnode	*current;
	size_t	max;

	nil = stack->nil;
	current = nil->next;
	max = 0;
	while (current != NULL && current != nil)
	{
		if (max < current->num)
			max = current->num;
		current = current->next;
	}
	return (max);
}

// find the minimum value on given stack
size_t	get_min(t_dstack *stack)
{
	t_dnode	*nil;
	t_dnode	*current;
	size_t	min;

	nil = stack->nil;
	current = nil->next;
	min = SIZE_T_MAX;
	while (current != NULL && current != nil)
	{
		if (current->num < min)
			min = current->num;
		current = current->next;
	}
	return (min);
}
