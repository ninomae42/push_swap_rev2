/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:44:21 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/06 16:44:22 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

bool	is_argument_valid(const char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	while (*s != '\0')
	{
		if (!ft_isdigit(*s))
			return (false);
		s++;
	}
	return (true);
}
