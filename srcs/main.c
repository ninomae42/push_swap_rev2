#include "push_swap.h"

int	main(int argc, char **argv)
{
	size_t		i;
	int			ret;
	int			err;
	t_ops		*ops;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	i = 1;
	ops = ops_init();
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
		ops_push_back(ops, ret);
		i++;
	}
	ops_print(ops);
	t_opsnode	*nil;
	nil = ops->nil;
	ops_erace(ops, nil->next);
	ops_print(ops);
	ops_erace(ops, nil->next);
	ops_print(ops);
	ops_erace(ops, nil->prev);
	ops_print(ops);
	ops_erace(ops, nil->prev);
	ops_print(ops);
	ops_clear(ops);
	ops_print(ops);
	exit(EXIT_SUCCESS);
}
