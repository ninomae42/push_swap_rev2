/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:46:51 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/06 16:46:51 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_stack_sorted(t_dstack *stack)
{
	t_dnode	*nil;
	t_dnode	*current;

	if (stack->size < 2)
		return (true);
	nil = stack->nil;
	current = nil->next;
	while (current != NULL && current != nil && current->next != nil)
	{
		if (current->num > current->next->num)
			return (false);
		current = current->next;
	}
	return (true);
}

bool	is_lte_key_exist(t_dstack *stack, int key)
{
	t_dnode	*nil;
	t_dnode	*current;

	nil = stack->nil;
	current = nil->next;
	while (current != NULL && current != nil)
	{
		if (current->num <= key)
			return (true);
		current = current->next;
	}
	return (false);
}
