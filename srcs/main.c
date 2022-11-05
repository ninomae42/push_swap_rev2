#include "push_swap.h"

typedef struct s_controller
{
	int			argc;
	char		**argv;
	t_dstack	*stack_a;
	t_dstack	*stack_b;
	t_ops		*ops;
}	t_controller;

typedef t_controller	t_cont;

t_cont	*init_push_swap(int argc, char **argv)
{
	t_cont	*controller;

	controller = (t_cont *)malloc_or_exit(sizeof(t_cont));
	controller->argc = argc;
	controller->argv = argv;
	controller->stack_a = dstack_init();
	controller->stack_b = dstack_init();
	controller->ops = ops_init();
	return (controller);
}

void	receive_cmdline_argument(t_cont *controller)
{
	size_t	i;
	char	**argv;
	int		ret;

	i = 1;
	argv = controller->argv;
	while (argv[i] != NULL)
	{
		errno = 0;
		ret = ft_atoi_int(argv[i]);
		if (errno != 0)
		{
			ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		dstack_push_back(controller->stack_a, ret);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_cont		*controller;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	controller = init_push_swap(argc, argv);
	receive_cmdline_argument(controller);
	controller->stack_b = dstack_copy(controller->stack_a);
	dstack_print(controller->stack_a);
	dstack_print(controller->stack_b);
	puts("");
	ops_print(controller->ops);
	exit(EXIT_SUCCESS);
}
