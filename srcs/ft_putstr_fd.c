#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	ft_putstr_fd(const char *s, int fd)
{
	size_t	len;
	ssize_t	bytes_written;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	while (INT_MAX < len)
	{
		bytes_written = write(fd, s, INT_MAX);
		if (bytes_written == -1)
			continue ;
		s += bytes_written;
		len -= bytes_written;
	}
	write(fd, s, len);
}
