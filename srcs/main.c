#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_cont		*controller;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	controller = init_push_swap(argc, argv);
	receive_cmdline_argument(controller);
	sort_and_check_duplication(controller);

	dstack_print(controller->stack_a);
	dstack_print(controller->stack_b);
	puts("");

	print_array(controller->sorted_array, controller->stack_a->size);
	puts("");

	ops_print(controller->ops);
	exit(EXIT_SUCCESS);
}
