/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:46:23 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/06 16:46:24 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_opsnode	*opsnode_new(t_eops operation)
{
	t_opsnode	*new;

	new = (t_opsnode *)malloc_or_exit(sizeof(t_opsnode));
	new->operation = operation;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_ops	*ops_init(void)
{
	t_ops	*ops;

	ops = (t_ops *)malloc_or_exit(sizeof(t_ops));
	ops->nil = opsnode_new(none);
	ops->size = 0;
	ops->nil->next = ops->nil;
	ops->nil->prev = ops->nil;
	return (ops);
}

void	ops_push_back(t_ops *ops, t_eops operation)
{
	t_opsnode	*nil;
	t_opsnode	*new;

	if (ops == NULL || ops->nil == NULL)
		return ;
	nil = ops->nil;
	new = opsnode_new(operation);
	if (ops->size == 0)
	{
		nil->next = new;
		nil->prev = new;
		new->next = nil;
		new->prev = nil;
	}
	else
	{
		new->next = nil;
		new->prev = nil->prev;
		nil->prev->next = new;
		nil->prev = new;
	}
	ops->size += 1;
}

void	ops_print(t_ops *ops)
{
	t_opsnode	*nil;
	t_opsnode	*current;

	if (ops == NULL || ops->size == 0 || ops->nil == NULL)
		return ;
	nil = ops->nil;
	current = nil->next;
	printf("Operations(%zu): ", ops->size);
	while (current != NULL && current != nil)
	{
		printf("%s ", enum_ops_to_string(current->operation));
		current = current->next;
	}
	puts("");
}

char	*enum_ops_to_string(t_eops operation)
{
	if (operation == sa)
		return ("sa");
	if (operation == sb)
		return ("sb");
	if (operation == ss)
		return ("ss");
	if (operation == pa)
		return ("pa");
	if (operation == pb)
		return ("pb");
	if (operation == ra)
		return ("ra");
	if (operation == rb)
		return ("rb");
	if (operation == rr)
		return ("rr");
	if (operation == rra)
		return ("rra");
	if (operation == rrb)
		return ("rrb");
	if (operation == rrr)
		return ("rrr");
	return ("");
}
