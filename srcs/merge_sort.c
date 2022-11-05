#include "push_swap.h"

static void	merge(int *a, int *buf, size_t left, size_t right)
{
	size_t	i;
	size_t	buf_index;
	size_t	mid;
	size_t	iterator_left;
	size_t	iterator_right;

	mid = left + (right - left) / 2;
	buf_index = 0;
	i = left;
	while (i < mid)
		buf[buf_index++] = a[i++];
	i = right - 1;
	while (mid <= i)
		buf[buf_index++] = a[i--];
	iterator_left = 0;
	iterator_right = buf_index - 1;
	i = left;
	while (i < right)
	{
		if (buf[iterator_left] <= buf[iterator_right])
			a[i] = buf[iterator_left++];
		else
			a[i] = buf[iterator_right--];
		i++;
	}
}

void	merge_sort(int *a, int *buf, size_t left, size_t right)
{
	size_t	mid;

	if (right - left == 1)
		return ;
	mid = left + (right - left) / 2;
	merge_sort(a, buf, left, mid);
	merge_sort(a, buf, mid, right);
	merge(a, buf, left, right);
}
