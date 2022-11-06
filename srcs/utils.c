/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:46:56 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/06 16:46:57 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*malloc_or_exit(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		exit(EXIT_FAILURE);
	return (ptr);
}
