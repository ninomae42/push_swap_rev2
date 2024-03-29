/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:45:39 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/10 19:33:40 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	ft_putchar_fd(const char c, int fd)
{
	write(fd, &c, sizeof(char));
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

void	ft_putendl_fd(const char *s, int fd)
{
	if (s == NULL)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
