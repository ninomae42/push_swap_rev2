#include "push_swap.h"

t_cont	*init_push_swap(int argc, char **argv)
{
	t_cont	*controller;

	controller = (t_cont *)malloc_or_exit(sizeof(t_cont));
	controller->argc = argc;
	controller->argv = argv;
	controller->stack_a = dstack_init();
	controller->stack_b = dstack_init();
	controller->ops = ops_init();
	controller->sorted_array = NULL;
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

void	sort_and_check_duplication(t_cont *controller)
{
	int	*buf;
	int	*array;

	buf = (int *)malloc(sizeof(int) * controller->stack_a->size);
	array = stack_to_array(controller->stack_a);
	merge_sort(array, buf, 0, controller->stack_a->size);
	if (is_duplicate_exist(array, controller->stack_a->size))
	{
		ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	free(buf);
	controller->sorted_array = array;
}
