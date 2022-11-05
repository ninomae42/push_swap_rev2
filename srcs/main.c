#include "push_swap.h"

int	main(int argc, char **argv)
{
	size_t		i;
	int			ret;
	int			err;
	t_ops		*ops;
	t_dstack	*stack_a;
	t_dstack	*stack_b;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	i = 1;
	ops = ops_init();
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
	stack_b = dstack_copy(stack_a);
	dstack_print(stack_a);
	dstack_print(stack_b);
	swap_a(stack_a, ops);
	swap_b(stack_b, ops);
	dstack_print(stack_a);
	dstack_print(stack_b);
	swap_same(stack_a, stack_b, ops);
	dstack_print(stack_a);
	dstack_print(stack_b);
	ops_print(ops);
	exit(EXIT_SUCCESS);
}
