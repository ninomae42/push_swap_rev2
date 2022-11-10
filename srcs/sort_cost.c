/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:57:55 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/10 20:57:57 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// get a moving cost from top with given value
size_t	get_cost_from_top(t_dstack *stack, size_t value)
{
	size_t	cost;
	t_dnode	*nil;
	t_dnode	*current;

	cost = 0;
	nil = stack->nil;
	current = nil->next;
	while (current != NULL && current != nil)
	{
		if (current->num == value)
			break ;
		cost++;
		current = current->next;
	}
	return (cost);
}

// get a moving cost from bottom with given value
size_t	get_cost_from_bottom(t_dstack *stack, size_t value)
{
	size_t	cost;
	t_dnode	*nil;
	t_dnode	*current;

	cost = 1;
	nil = stack->nil;
	current = nil->prev;
	while (current != NULL && current != nil)
	{
		if (current->num == value)
			break ;
		cost++;
		current = current->prev;
	}
	return (cost);
}
