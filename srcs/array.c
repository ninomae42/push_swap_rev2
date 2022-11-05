#include "push_swap.h"

int	*stack_to_array(t_dstack *stack)
{
	int		*array;
	size_t	i;
	t_dnode	*current;
	t_dnode	*nil;

	if (stack == NULL || stack->size == 0)
		return (NULL);
	array = (int *)malloc_or_exit(sizeof(int) * stack->size);
	nil = stack->nil;
	current = nil->next;
	i = 0;
	while (current != NULL && current != nil)
	{
		array[i] = current->num;
		current = current->next;
		i++;
	}
	return (array);
}

void	print_array(int *array, size_t size)
{
	size_t	i;

	if (array == NULL)
		return ;
	i = 0;
	printf("Current array(%zu): ", size);
	while (i < size)
	{
		printf("%d ", array[i]);
		i++;
	}
}

bool	is_duplicate_exist(int *array, size_t size)
{
	size_t	i;

	i = 0;
	while (i + 1 < size)
	{
		if (array[i] == array[i + 1])
			return (true);
		i++;
	}
	return (false);
}
