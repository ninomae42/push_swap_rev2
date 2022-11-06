/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:45:32 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/06 16:45:33 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f'
		|| c == '\n' || c == '\r'
		|| c == '\t' || c == '\v');
}

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

static int	is_overflow(long current, long sign, char next)
{
	if (0 < sign)
	{
		if (INT_MAX / 10 < current)
			return (1);
		current = current * 10;
		if ((INT_MAX - current) < (next - '0'))
			return (1);
	}
	else
	{
		current = current * (-1);
		if (current < (INT_MIN / 10))
			return (1);
		current = current * 10;
		if (-(next - '0') < (INT_MIN - current))
			return (1);
	}
	return (0);
}

static long	do_conversion(const char *str, long sign, bool *is_err)
{
	long	ret;

	ret = 0;
	while (ft_isdigit(*str))
	{
		if (is_overflow(ret, sign, *str))
		{
			*is_err = 1;
			if (0 < sign)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (ret);
}

int	ft_atoi_int(const char *str)
{
	long	ret;
	long	sign;
	bool	is_err;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	if (!ft_isdigit(*str))
	{
		errno = EINVAL;
		return ((int)ret);
	}
	is_err = 0;
	ret = do_conversion(str, sign, &is_err);
	if (is_err)
	{
		errno = ERANGE;
		return ((int)ret);
	}
	return ((int)(sign * ret));
}
