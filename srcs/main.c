#include "push_swap.h"

int	main(int argc, char **argv)
{
	size_t		i;
	int			ret;
	int			err;
	t_dstack	*stack_a;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	i = 1;
	stack_a = dstack_init();
	while (argv[i] != NULL)
	{
		if (!is_argument_valid(argv[i]))
		{
			printf("error occured, with value: %s\n", argv[i]);
			exit(EXIT_FAILURE);
		}
		ret = ft_atoi_int(argv[i]);
		err = errno;
		if (err != 0)
		{
			printf("error occured, with [code: %d, value: %s]\n", err, argv[i]);
			exit(EXIT_FAILURE);
		}
		dstack_push_back(stack_a, ret);
		i++;
	}
	t_dstack *stack_b =  dstack_copy(stack_a);
	dstack_print(stack_a);
	
	dstack_pop_front(stack_a);
	dstack_print(stack_a);

	dstack_pop_front(stack_a);
	dstack_print(stack_a);

	dstack_pop_front(stack_a);
	dstack_print(stack_a);

	dstack_pop_front(stack_a);
	dstack_print(stack_a);

	dstack_pop_front(stack_a);
	dstack_print(stack_a);

	dstack_pop_front(stack_a);
	dstack_print(stack_a);

	dstack_pop_front(stack_a);
	dstack_print(stack_a);

	dstack_clear(stack_a);
	dstack_print(stack_a);
	dstack_print(stack_b);
	dstack_clear(stack_b);
	dstack_print(stack_b);
	dstack_clear(stack_b);
	exit(EXIT_SUCCESS);
}
