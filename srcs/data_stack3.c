/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_stack3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:58:17 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/10 20:58:18 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	dstack_find(t_dstack *stack, size_t target)
{
	t_dnode	*nil;
	t_dnode	*current;

	nil = stack->nil;
	current = nil->next;
	while (current != NULL && current != nil)
	{
		if (current->num == target)
			return (true);
		current = current->next;
	}
	return (false);
}
