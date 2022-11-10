/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_stack2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:46:28 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/10 19:34:45 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_erace(t_ops *ops, t_opsnode *node)
{
	t_opsnode	*prev_node;
	t_opsnode	*next_node;
	t_opsnode	*nil;

	if (ops == NULL || node == NULL || ops->size == 0 || ops->nil == NULL)
		return ;
	nil = ops->nil;
	if (node == nil)
	{
		free(node);
		return ;
	}
	prev_node = node->prev;
	next_node = node->next;
	prev_node->next = node->next;
	next_node->prev = node->prev;
	free(node);
	ops->size -= 1;
}

void	ops_clear(t_ops *ops)
{
	t_opsnode	*nil;
	t_opsnode	*current;
	t_opsnode	*tmp;

	if (ops == NULL || ops->size == 0 || ops->nil == NULL)
		return ;
	nil = ops->nil;
	current = nil->next;
	while (current != NULL && current != nil)
	{
		tmp = current;
		current = current->next;
		ops_erace(ops, tmp);
	}
	nil->next = nil;
	nil->prev = nil;
}

void	ops_print_result(t_cont *cont)
{
	t_opsnode	*nil;
	t_opsnode	*current;

	nil = cont->ops->nil;
	current = nil->next;
	while (current != NULL && current != nil)
	{
		ft_putendl_fd(enum_ops_to_string(current->operation), STDOUT_FILENO);
		current = current->next;
	}
}
