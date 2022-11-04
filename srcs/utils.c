#include "push_swap.h"

void	*malloc_or_exit(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		exit(EXIT_FAILURE);
	return (ptr);
}
