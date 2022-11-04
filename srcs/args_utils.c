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
